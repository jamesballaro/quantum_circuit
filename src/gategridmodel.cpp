#include "gategridmodel.h"
#include "q_circuit.h"    
#include <QDebug>

GateGridModel::GateGridModel(q_circuit* circuit, QObject* parent)
    : QAbstractTableModel(parent), m_circuit(circuit)
{   
    m_bitCount = circuit->get_nbits();
    m_timeCount = circuit->get_maxgates();

    m_data.resize(m_bitCount);
    for (auto& row : m_data) {
        row.resize(m_timeCount);
    }
    try{
        syncFromCircuit();
    }
    catch (const std::exception& e) {
        std::cerr << "[GateGridModel] " << "Exception occurred: " << e.what() << std::endl;
    }  
}

int GateGridModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // qDebug() << "GateGridModel rowCount:" << m_bitCount;
    return m_bitCount;
}

int GateGridModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // qDebug() << "GateGridModel colCount:" << m_timeCount;
    return m_timeCount;
}

QVariant GateGridModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int r = index.row();
    int c = index.column();

    if (role == Qt::UserRole + 1) {  // Use the defined role for gateType
        // qDebug() << "gateType requested at (" << r << "," << c << "):" << m_data[r][c];
        if(m_data[r][c].isEmpty()){
            qDebug()<<"m_data["<<r<<"]["<<c<<"] is empty";
            return QString("");  // Default type
        }
        return m_data[r][c];  
    }
    return QVariant();
}

bool GateGridModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int r = index.row();
    int c = index.column();
    if (r < 0 || r >= m_bitCount || c < 0 || c >= m_timeCount)
        return false;

    // Update the 2D grid with the new gate name
    m_data[r][c] = value.toString();

    // Notify any views: data changed in [r, c]
    // emit dataChanged(index, index, {role});
    return true;
}

QHash<int, QByteArray> GateGridModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "display";
    roles[Qt::UserRole + 1] = "gateType";
    return roles;
}

void GateGridModel::insertGate(const QString &gateType, int row, int column)
{
    qDebug()<<"Gate Insert 1"<<row<<m_bitCount<<column<<m_timeCount;
    if (row < 0 || row > m_bitCount || column < 0) //|| column >= m_timeCount
        return;

    // setData with EditRole
    QModelIndex idx = index(row, column);
    setData(idx, gateType, Qt::EditRole);
    syncToCircuit();
}

void GateGridModel::removeGate(int row, int column)
{
    if (row < 0 || row >= m_bitCount || column < 0 || column >= m_timeCount)
        return;

    // setData with an empty string => no gate
    QModelIndex idx = index(row, column);
    setData(idx, QString(), Qt::EditRole);
}

void GateGridModel::clearAll()
{
    for (int r = 0; r < m_bitCount; ++r) {
        for (int c = 0; c < m_timeCount; ++c) {
            QModelIndex idx = index(r, c);
            setData(idx, QString(), Qt::EditRole);
        }
    }
}

void GateGridModel::syncFromCircuit()
{
    if (!m_circuit){
        throw std::runtime_error("No circuit available to load from");
    }
    
    // if(m_circuit->get_nbits() < m_bitCount - 1 || m_circuit->get_maxgates() < m_timeCount -1){
    //     throw std::runtime_error("Circuit smaller than expected.");
    // }
    else{
        m_bitCount = m_circuit->get_nbits();
        m_timeCount = m_circuit->get_maxgates();

        m_data.resize(m_bitCount); // Resize the outer vector
        for (auto& row : m_data) {
            row.resize(m_timeCount); // Resize each inner QVector
        }

        for (int r = 0; r < m_bitCount; r++) {
            for (int c = 0; c < m_timeCount; c++) {
                try{
                    auto component_ptr = m_circuit->get_components_vector()[r][c];
                    if(!component_ptr){
                        throw std::runtime_error("Empty circuit component encountered.");
                    }
                    else{
                        m_data[r][c] = QString::fromStdString(component_ptr->get_type());
                    }
                }
                    catch(std::exception& e){
                        qDebug()<<QString::fromStdString(e.what());
                }
            }
        }
    }
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(m_bitCount - 1, m_timeCount - 1);
    emit dataChanged(topLeft, bottomRight);
}

void GateGridModel::syncToCircuit()
{
    qDebug()<<"Sync";
    if (!m_circuit)
        return;
    else{
        for (int r = 0; r < m_bitCount; r++) {
            for (int c = 0; c < m_timeCount; c++) {
                QString gateName = m_data[r][c];
                if (!gateName.isEmpty()){
                    qDebug()<<"Adding gate"<<gateName<<"to"<<r<<c;
                    m_circuit->add_gate(gateName.toStdString(), {r}, c);
                }
                else{
                     m_circuit->remove_gate(r, c);
                }
            }
        }
        QModelIndex topLeft = index(0, 0);
        QModelIndex bottomRight = index(m_bitCount - 1, m_timeCount - 1);
        emit dataChanged(topLeft, bottomRight);
    }
}

void GateGridModel::addBitRow()
{
    if (!m_circuit){
        qDebug() << "Error: Null circuit";
        return;
    }
    else{
        // qDebug()<< "Before adding:"<<std::to_string(m_circuit->get_nbits());

        // std::string debug_msg{m_circuit->debug_circuit()};
        // qDebug()<<QString::fromStdString(debug_msg);
        
        m_circuit->add_bit_row();
        // qDebug()<< "After adding:"<<std::to_string(m_circuit->get_nbits());

        // debug_msg = m_circuit->debug_circuit();
        // qDebug()<<QString::fromStdString(debug_msg);

        try{
            syncFromCircuit();
        }catch(std::exception &e){
            qDebug()<<"Error: syncFromCircuit "<<e.what();
        }
    }
}

void GateGridModel::removeBitRow()
{
    if (!m_circuit){
        qDebug() << "Error: Null circuit";
        return;
    }
    else{
        // qDebug()<< "Before adding:"<<std::to_string(m_circuit->get_nbits());

        // std::string debug_msg{m_circuit->debug_circuit()};
        // qDebug()<<QString::fromStdString(debug_msg);
        
        m_circuit->remove_bit_row();
        // qDebug()<< "After adding:"<<std::to_string(m_circuit->get_nbits());

        // debug_msg = m_circuit->debug_circuit();
        // qDebug()<<QString::fromStdString(debug_msg);

        try{
            syncFromCircuit();
        }catch(std::exception &e){
            qDebug()<<"Error: syncFromCircuit "<<e.what();
        }
    }
}



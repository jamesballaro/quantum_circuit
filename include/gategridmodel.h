#ifndef GATEGRIDMODEL_H
#define GATEGRIDMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QString>
#include <memory>  
#include "q_circuit.h"


class GateGridModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    int m_bitCount;
    int m_timeCount;
    QVector<QVector<QString>> m_data;
    q_circuit* m_circuit;
public:

    explicit GateGridModel(q_circuit* circuit = nullptr, QObject* parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void insertGate(const QString &gateType, int row, int column);
    void removeGate(int row, int column);
    void addBitRow();
    void removeBitRow();
    void clearAll();
    void syncFromCircuit();
    void syncToCircuit();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    // void add_gate(std::string gate, int bit, int time);
    // void multi_qbit_gate(std::shared_ptr<component> gate, int qbit_range, int num_qubits);
    // void series_add(std::string gate_choice, std::shared_ptr<component> gate, int bit, int time);
    // void parallel_add(std::shared_ptr<component> gate);
   
    // void create_circuit();
    // void draw_circuit();

    // void calculate_circuit_matrix(int gate_pos);
    // void get_circuit_matrix();
    // void save();
    // void load();
    // void add_to_circuit(std::shared_ptr<q_circuit> circuit, int circ_no);

    inline int bitCount() const { return m_bitCount; }
    inline int timeCount() const { return m_timeCount; }
};

#endif // GATEGRIDMODEL_H
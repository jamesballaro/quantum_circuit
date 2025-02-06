#include "qGUI.h"
#include <QLibraryInfo>

qGUI::qGUI(QApplication *app, QObject *parent)
    : QObject(parent)
{   
    m_circuit = std::make_shared<q_circuit>();
    // m_circuit->add_gate("Hadamard",{0},1);
    
    try{
    std::string debug_msg{m_circuit->debug_circuit()};
        qDebug()<<QString::fromStdString(debug_msg);}
    catch(std::exception& e){
        qDebug()<<QString::fromStdString(e.what());
    }

    m_gateModel = std::make_unique<GateGridModel>(m_circuit.get(), this);

    // const QMetaObject* metaObject = this->metaObject();
    // for (int i = 0; i < metaObject->methodCount(); ++i) {
    //     qDebug() << "Exposed method:" << metaObject->method(i).methodSignature();
    // }

    qDebug() << "Is m_gateModel initialized?" << (m_gateModel != nullptr);
    emit gateModelChanged();
}
qGUI::~qGUI() {}
void qGUI::debug()
{
    qDebug()<<"Debugging: qGUI::debug() called";
}
void qGUI::loadQml()
{
  // Change this, not elegant but grants hot reload functionality
  qDebug() << "Reloading QML...";

    QObject *rootObject = m_engine->rootObjects().isEmpty() ? nullptr : m_engine->rootObjects().first();
    if (rootObject) {
        qDebug() << "Closing the old QML window...";
        rootObject->deleteLater();  // Deletes the root object and all its children
    }

  QString projectRoot = QCoreApplication::applicationDirPath() + "/../../";
  QString qmlFilePath = projectRoot + "src/qml/main.qml";
  
  m_engine->clearComponentCache();
  m_engine->load(QUrl::fromLocalFile(qmlFilePath));
  if (m_engine->rootObjects().isEmpty())
      return;
}

QString qGUI::gateInfo(const QString &gateType)
{   
    std::string gate = gateType.toStdString();
    std::string info;
    
    if(library::string_to_ptr(gate) == nullptr){
        throw std::runtime_error("No match found");
    }
    info = library::string_to_ptr(gate)->get_info();

    return QString::fromStdString(info);
}

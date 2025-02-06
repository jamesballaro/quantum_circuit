#include "qGUI.h"
#include <iostream> 
#include <QFile>    
#include <QtQuickControls2>


int main(int argc, char *argv[])
{
    try {  
        QApplication app(argc, argv);
        QQuickStyle::setStyle("Material");
        QQmlApplicationEngine engine;

        std::unique_ptr<qGUI> qgui = std::make_unique<qGUI>(&app);
        qgui->setEngine(&engine);

        engine.rootContext()->setContextProperty("qgui", qgui.get());
        engine.rootContext()->setContextProperty("gateModel", qgui->gateModel());

        engine.addImportPath(QML2_IMPORT_PATH);
        engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));   

        qDebug() << "Is qgui accessible? " << (qgui.get());
        qDebug() << "Is qgui accessible? " << (qgui->gateModel());

        // QObject::connect(&engine, &QQmlApplicationEngine::warnings, [](const QList<QQmlError> &warnings) {
        //     for (const QQmlError &warning : warnings) {
        //         qDebug() << "QML Warning:" << warning.toString();
        //     }
        // });

        if (engine.rootObjects().isEmpty()) {
            qDebug() << "Error: Failed to load QML file or components.";
            return -1;
        }
        return app.exec();
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
    // menu();
    return 0;
}


// qDebug() << "Checking if main.qml exists:" << QFile::exists(":/qml/main.qml");
// qDebug() << "Checking if qmldir exists:" << QFile::exists(":/qml/components/qmldir");
// qDebug() << "Checking if hadamard.png exists:" << QFile::exists(":/qml/icons/hadamard.png");
// qDebug() << "Does qrc:/qml/components/qmldir exist?" << QFile::exists(":/qml/components/qmldir");
// QString projectRoot = QCoreApplication::applicationDirPath() + "/../../src/qml/";
// QString qmlFilePath = projectRoot + "main.qml";
// QString componentsPath = projectRoot + "components";
// qDebug() << "QML Import Paths:" << engine.importPathList();

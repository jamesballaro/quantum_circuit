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

        qGUI qgui(&app);
        qgui.setEngine(&engine);

        engine.rootContext()->setContextProperty("qgui", &qgui);

        QString projectRoot = QCoreApplication::applicationDirPath() + "/../../src/qml/";
        QString qmlFilePath = projectRoot + "main.qml";
        QString componentsPath = projectRoot + "components";

        engine.addImportPath(componentsPath);
        engine.load(QUrl::fromLocalFile(qmlFilePath));

        // QObject::connect(&engine, &QQmlApplicationEngine::warnings, [](const QList<QQmlError> &warnings) {
        //     for (const QQmlError &warning : warnings) {
        //         qDebug() << "QML Warning:" << warning.toString();
        //     }
        // });

        // Debug root objects
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

#ifndef QGUI_H

#define QGUI_H

#include "q_circuit.h"
#include <chrono>
#include <thread>
#include "gate_a_base.h"
#include "matrix.h"
#include "multi_bit_components.h"
#include "single_bit_components.h"
#include "toolbox.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>

class qGUI : public QObject {
    Q_OBJECT

public:
    qGUI(QApplication *app = nullptr, QObject *parent = nullptr);
    ~qGUI();
    void setEngine(QQmlApplicationEngine *engine) { m_engine = engine; }
private:
    std::shared_ptr<q_circuit> circuit;
    QQmlApplicationEngine* m_engine;    
public slots:
    void loadQml();
    void launch();
    void submenu(std::shared_ptr<q_circuit> circuit);
    void debugtest();
};

#endif //MENU_H

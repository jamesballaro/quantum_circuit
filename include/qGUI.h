#ifndef QGUI_H

#define QGUI_H

#include "q_circuit.h"
#include "gategridmodel.h"
#include <chrono>
#include <thread>
#include "library.h"
#include "matrix.h"
#include "multi_bit_gates.h"
#include "single_bit_gates.h"
#include "toolbox.h"
#include <memory>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class qGUI : public QObject {
    Q_OBJECT

private:
    std::shared_ptr<q_circuit> m_circuit;
    QQmlApplicationEngine* m_engine;    
    std::unique_ptr<GateGridModel> m_gateModel; 

    Q_PROPERTY(GateGridModel* gateModel READ gateModel NOTIFY gateModelChanged)

public:
    qGUI(QApplication *app = nullptr, QObject *parent = nullptr);
    ~qGUI();
    void setEngine(QQmlApplicationEngine *engine) { m_engine = engine; }
    GateGridModel* gateModel() const { return m_gateModel.get(); } 

public slots:
    void loadQml();
    void debug();
    QString gateInfo(const QString &gateType);

    // void save();
    // void load();
    // void add_to_circuit(std::shared_ptr<q_circuit> circuit, int circ_no);
    // void addGate();
    // void gate_info();
    // void create_circuit();
    // void draw_circuit();
    // void remove_gate();
    // void calculate_circuit_matrix(int gate_pos);
    // void get_circuit_matrix();
signals:
    void gateModelChanged();
};

#endif //qGUI.H
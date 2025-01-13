#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include "q_circuit.h"
#include <chrono>
#include <thread>
#include "gate_a_base.h"
#include "matrix.h"
#include "multi_bit_components.h"
#include "single_bit_components.h"
#include "toolbox.h"

class Menu : public QMainWindow {
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void createCircuit();
    void viewGateInfo();
    void exitProgram();

private:
    std::shared_ptr<q_circuit> circuit;
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QPushButton *createCircuitButton;
    QPushButton *viewGateInfoButton;
    QPushButton *exitButton;
    QLabel *welcomeLabel;
};

#endif 
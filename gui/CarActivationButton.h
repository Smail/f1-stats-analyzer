#pragma once

#include <QPushButton>
#include <QAbstractSeries>

class CarActivationButton : public QPushButton {
Q_OBJECT;
public:
    explicit CarActivationButton(QAbstractSeries* series, QWidget* parent = nullptr);

    void setIsActive(bool isActive);

    [[nodiscard]] bool isActive() const;

    void toggleState();

private:
    void updateState();

    void updateColor();

private slots:

    void handleButton();

private:
    QAbstractSeries* series;
    QColor activeColor{50, 205, 50};
    QColor inactiveColor{188, 27, 34};
    bool m_isActive{true};
};

#include "CarActivationButton.h"

CarActivationButton::CarActivationButton(QAbstractSeries* series, QWidget* parent)
        : QPushButton(parent),
          series{series} {
    updateColor();
    connect(this, &QPushButton::clicked, this, &CarActivationButton::handleButton);
}

void CarActivationButton::setIsActive(bool isActive) {
    m_isActive = isActive;
    updateState();
}

bool CarActivationButton::isActive() const {
    return m_isActive;
}

void CarActivationButton::toggleState() {
    setIsActive(!m_isActive);
};

void CarActivationButton::updateState() {
    updateColor();
    series->setVisible(m_isActive);
    update();
}

void CarActivationButton::updateColor() {
    QPalette pal = palette();

    pal.setColor(QPalette::Button, m_isActive ? activeColor : inactiveColor);
    setAutoFillBackground(true);
    setPalette(pal);
}

void CarActivationButton::handleButton() {
    toggleState();
}

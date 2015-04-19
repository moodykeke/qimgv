#include "thumbnaillabel.h"

ThumbnailLabel::ThumbnailLabel() : hovered(false) {
    setMouseTracking(true);
}

void ThumbnailLabel::mousePressEvent ( QMouseEvent * event ) {
    Q_UNUSED(event)
    emit clicked(this);
}

void ThumbnailLabel::paintEvent(QPaintEvent* event) {
    QLabel::paintEvent(event);
    if(hovered) {
        QPainter painter(this);
        painter.fillRect(rect(), QBrush(QColor(40,40,40,80)));
    }
}

void ThumbnailLabel::enterEvent(QEvent *event) {
    Q_UNUSED(event)
    hovered = true;
    update();
}

void ThumbnailLabel::leaveEvent(QEvent *event) {
    Q_UNUSED(event)
    hovered = false;
    update();
}

ThumbnailLabel::~ThumbnailLabel() {

}


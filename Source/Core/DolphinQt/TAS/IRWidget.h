// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <QDialog>

#include "Common/CommonTypes.h"

class IRWidget : public QWidget
{
  Q_OBJECT
public:
  explicit IRWidget(QWidget* parent);

signals:
  void ChangedX(u16 x);
  void ChangedY(u16 y);

public slots:
  void SetX(u16 x);
  void SetY(u16 y);

protected:
  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void handleMouseEvent(QMouseEvent* event);

private:
  u16 m_x = 0;
  u16 m_y = 0;
};

// Should be part of class but fails to compile on mac os
static const u16 ir_max_x = 1023;
static const u16 ir_max_y = 767;

// Copyright (c) 2021 The Orbit Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ORBIT_GPP_PROJECT_H_
#define ORBIT_GPP_PROJECT_H_

#include <QByteArray>
#include <QString>
#include <QVector>
#include <tuple>

#include "OrbitBase/Result.h"

namespace orbit_ggp {

struct Project {
  QString display_name;
  QString id;

  static ErrorMessageOr<QVector<Project>> GetListFromJson(const QByteArray& json);

  friend bool operator==(const Project& lhs, const Project& rhs) {
    return std::tie(lhs.display_name, lhs.id) == std::tie(rhs.display_name, rhs.id);
  }
};

}  // namespace orbit_ggp

#endif  // ORBIT_GPP_PROJECT_H_
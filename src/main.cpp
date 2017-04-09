/**
 *  Tanca, a petanque contests manager
 *  Copyright (C) 2016  Anthony Rabine <anthony.rabine@tarotclub.fr>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MainWindow.h"
#include <QApplication>
#include <QtQuick>
/*
#include <chrono>
#include <thread>
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
*/
#include "Tournament.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Register our component type with QML.
    qmlRegisterType<Tournament>("Tanca", 1, 0, "Tournament");

    MainWindow w;
    w.Initialize();
    w.show();

    return a.exec();
}

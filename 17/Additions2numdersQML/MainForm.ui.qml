import QtQuick 2.4

Rectangle {
    id: rectangle
    color: "#ececec";

    Column {
        spacing: 5
        anchors.centerIn: parent;

        Text {
            text: "Введите числа через пробел"
            font.family: "Helvetica"
            font.pointSize: 10
            color: "red"
        }

        Rectangle {
            id: textinputRect //Имя строки ввода

            //Размеры строки ввода
            width: 700
            height: 18

            //цвет строки ввода
            color: "#ffffff"

            TextInput {
                id: textinput
                objectName: "textinput"
                color: "#0066ff";
                selectionColor: "blue"
                font.pixelSize: 12;
                width: parent.width-4
                anchors.centerIn: parent
                focus: true
                text:"0.1 -4 5 -0.7 0 -2.8 3.6"
            }
        }

        //Кнопка
        Rectangle {
            id: button //Имя кнопки

            //Размеры кнопки
            width: 700
            height: 30

            //Цвет кнопки
            color: "#0066ff"

            //Текст кнопки
            Text {
                id: buttonLabel
                text: "Расчитать"
                color: "#ffffff";
                anchors.centerIn: parent;
            }

            //Действие мыши
            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                hoverEnabled: true;

                onClicked: _myClass.buttonClicked();
            }
        }

        Text {
            text: "Количество отрицательных чисел в массиве:"
            font.family: "Helvetica"
            font.pointSize: 10
            color: "red"
        }

        //Поле вывода
        Rectangle {
            id: memoRect1 //Имя поля вывода

            //Размеры поле вывода
            width: 700
            height: 35

            //Цвет поля вывода
            color: "#ffffff"

            TextEdit{
                id: memo1
                color: "#0066ff"
                objectName: "memo1"
                wrapMode: TextEdit.Wrap
                width:parent.width;
                readOnly:true
            }
        }

        Text {
            text: "Сумма модулей элементов массива, расположенных после минимального по модулю числа:"
            font.family: "Helvetica"
            font.pointSize: 10
            color: "red"
        }

        //Поле вывода
        Rectangle {
            id: memoRect2 //Имя поля вывода

            //Размеры поле вывода
            width: 700
            height: 35

            //Цвет поля вывода
            color: "#ffffff"

            TextEdit{
                id: memo2
                color: "#0066ff"
                objectName: "memo2"
                wrapMode: TextEdit.Wrap
                width:parent.width;
                readOnly:true
            }
        }


        Text {
            text: "Все отрицательные элементы массива заменены их квадратами. Массив отсортирован по возрастанию:"
            font.family: "Helvetica"
            font.pointSize: 10
            color: "red"
        }

        //Поле вывода
        Rectangle {
            id: memoRect3 //Имя поля вывода

            //Размеры поле вывода
            width: 700
            height: 35

            //Цвет поля вывода
            color: "#ffffff"

            TextEdit{
                id: memo3
                color: "#0066ff"
                objectName: "memo3"
                wrapMode: TextEdit.Wrap
                width:parent.width;
                readOnly:true
            }
        }
    }

}

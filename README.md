QConsoleWidget
========================


<p align="center">
	<img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat">
</p>

## Introduction
QConsoleWidget is a custom widgets for [Qt](https://www.qt.io/), which is a simulation of a console in Qt Widgets Applications. It inherits from `std::basic_streambuf` and `QPlainTextEdit`.

## Usage
1. Declare it in your own `*.ui` file:
    ```xml
    <widget class="QConsoleWidget" name="console">
    <property name="geometry">
        <rect>
        <x>10</x>
        <y>270</y>
        <width>501</width>
        <height>71</height>
        </rect>
    </property>
    </widget>
    ```
    Don't forget to declare this is a costom widget by:
    ```xml
    <customwidget>
    <class>QConsoleWidget</class>
    <extends>QPlainTextEdit</extends>
    <header>QConsoleWidget.h</header>
    </customwidget>
    ```
2. To print messages in this widget, redirect the stream buffer of your own `std::ostream` object to this widget.
    ```c++
    auto qout = new std::ostream(console);
    // console is the public member declared in your *.ui file above
    ```

3. There is a Qt Signal defined in this widget. Use it if you need to handle command input from the widget.
    ```c++
    // This signal will be emitted as long as the character newline('\n') is input as the last character.
    void cmdInput(QString cmd);
    ```
    You'd better emit some signal after you finish the command prossing. Just connect it to the slot defined in this widget.
    ```c++
    // print an IPython style tip message like "In[0]: "
    void PrintTip();
    ```
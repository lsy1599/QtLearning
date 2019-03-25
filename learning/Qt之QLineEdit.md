

```
QLineEdit* lineEdit = new QLineEdit(this);
lineEdit->setEchoMode(QLineEdit::Normal); //默认类型
lineEdit->setEchoMode(QLineEdit::NoEcho); //不回显
lineEdit->setEchoMode(QLineEdit::Password); //输入密码
lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit); //编辑时可见，离开焦点显示*
```

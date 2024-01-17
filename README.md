# TopicSelectSys

毕业选题管理系统TopicSelectSys是做数据库课设时做的一个简单小型的项目，基于Qt和MySQL实现，使用CMake管理项目。该项目能连接数据库实现增删改查，有操作交互界面，不想敲黑窗口的同学可以看一看这个项目。项目实现了一些小功能，例如按指定列升降序排序、表格搜索、不同身份登录到不同客户端等

课设题目
```
毕业设计选题系统
（1）开发内容
做出毕业设计选题系统的需求分析，概念结构分析，逻辑结构分析，数据库的实施及维护。
（2）开发要求
1.学生功能
学生可以在选题功能模块中浏览到自己心仪的题目并且选择该题目，之后等待出题老师录取。每个学生只能选择一条题目。
在老师没有录取之前学生能退掉自己已经选择的题目并且重新选择。
学生能修改自己注册时的个人信息，方便信息更新准确。
2.教师功能：
教师可以查询到已经选择了自己建立的题目的学生，并且有权利根据学生具体情况决定是否录取或是退选。
教师可以建立新题目供学生选择。
教师可以修改自己已经建立的题目信息，确保信息的准确性。
教师可以修改自己的注册资料，确保个人信息的准确性。
3.管理员功能：
管理员可以查看、修改和删除系统内的所有学生个人信息，教师个人信息，所有题目的信息。
管理员可以通过可选题目的查询，待录取题目的查询和已录取题目的查询了解整个毕业论文的总体工作进展情况

```

## 运行环境
Qt 6.5.1
MySQL 8.0.26

## 效果展示
### 登录界面
![](https://github.com/ming0725/TopicSelectSys/blob/main/doc/images/login.png)
### 客户端-学生端
![](https://github.com/ming0725/TopicSelectSys/blob/main/doc/images/stu_info.png)
### 学生选题
![](https://github.com/ming0725/TopicSelectSys/blob/main/doc/images/stu_select.png)
### 搜素功能
![](https://github.com/ming0725/TopicSelectSys/blob/main/doc/images/search.png)

## 打开项目
确保已经安装了Qt和MySQL
直接下载压缩包解压或使用Git克隆
使用Qt Creator或CLion打开（CLion需要配置Qt的编译器）
QtCreator-打开项目-选择文件夹-CMakeList.txt
CLion-Open-选择文件夹



## 编译运行
由于每个人MySQL用户名和密码都不一样
这里将MySQL连接时的用户名、密码和数据库等在外部设置
编译时将MySQL的设置改成自己的设置就可以了
```cmake
# mysql登录用户名
set(USER_VALUE "root")
# mysql登录密码
set(PASSWORD_VALUE "123456")
# mysql登录ip
set(IP_VALUE "127.0.0.1")
# mysql选择连接的数据库
set(DATABASE_VALUE "topic")
# mysql端口号
set(PORT_VALUE "3306")
# mysql安装的路径（有include lib文件夹的路径）
# 我安装的位置为"D:\Program Files\MySQL\MySQL Server 8.0"
# 但是目录有空格编译不成功，建议单独复制一份出来然后修改一下MYSQL_PATH
set(MYSQL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/mysql")
```

配置MySQL环境的时候路径带空格会导致编译不成功
这两种方式我都试了一遍，还是会有路径错误
"D:/Program Files/MySQL/MySQL Server 8.0"
"D:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0"

建议找到自己的MySQL安装目录，如果安装的时候没改就是在"C:\Program Files\MySQL\MySQL Server 8.0"
我这里改成了D盘，进入这个文件夹找到include和lib文件夹
在没空格的路径创建一个mysql文件夹（最好是这个项目文件夹），将include文件夹拷贝到这个文件夹下
再创建一个lib文件夹，将lib文件夹中的libmysql.lib放到该文件夹下
如果你是在项目文件夹下创建的（与CMakeLists.txt同目录），那么就设置好了
也可以在其它地方创建，保证路径没有空格或者中文名，再修改CMakeLists.txt.中这一行：

```cmake
set(MYSQL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/mysql")
```
${CMAKE_CURRENT_SOURCE_DIR}是项目文件夹，如果你是放在D:/mysql下就改为这样：
```cmake
set(MYSQL_PATH "D:/mysql")
```

如果编译时会误报病毒，在CMakeLists.txt中修改这行
```cmake
set(PROJECT_SOURCES
   # topic_win32.rc # 设置生成exe文件图标的文件
    ${IMAGE_FILES}
    ${INCLUDE_FILES}
    ${SOURCES_FILES}
    ${UI_FILES}
)
```
将设置图标的文件不加入编译就可以了，对使用没有影响，只是将编译出来的exe文件上个图标。



## 创建数据库
打开命令行界面，登录到MySQL客户端
```
mysql -u 用户名 -p
```
然后输入密码
创建一个database，名字为topic（其它名字也可以，需要修改CMake的DATABASE_VALUE）
```
mysql> create database topic;
mysql> use topic;
mysql> source topic.sql
```
数据库就自动创建好了，现在可以直接使用客户端了
# TopicSelectSys

毕业选题管理系统TopicSelectSys是做数据库课设时做的一个简单小型的项目，基于Qt和MySQL实现，使用CMake管理项目。该项目能连接数据库实现增删改查，有操作交互界面，不想敲黑窗口的同学可以看一看这个项目。项目实现了一些小功能，例如按指定列升降序排序、表格搜索、不同身份登录到不同客户端等

## 运行环境
Qt 6.5.1
MySQL 8.0.26

## 效果展示

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
在没空格的路径创建一个mysql文件夹，将include文件夹拷贝到这个文件夹下
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
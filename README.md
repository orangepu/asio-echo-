# asio-echo

初学linux服务器编程

    编译echo.cpp时需要在最后加-lboost_system
    编译echoClient.cpp时需要在最后加-lboost_system -lpthread

    运行echo.cpp时需要传入想注册的端口号（非公共端口）。
    运行echoClient.cpp时需要传入服务器 ip地址 和 服务器所在的端口号。

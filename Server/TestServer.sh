#!/bin/bash
g++ -I./include ThreadPool.cpp Group.cpp Server.cpp PacketParser.cpp PingThread.cpp ExecuteThread.cpp TestServer.cpp -o TestServer -lpthread

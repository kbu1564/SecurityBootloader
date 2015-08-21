#!/bin/bash
g++ -I./include ThreadPool.cpp Group.cpp Server.cpp PacketParser.cpp TestServer.cpp -o TestServer -lpthread

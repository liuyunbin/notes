#ifndef TINY_CHAT_H_
#define TINY_CHAT_H_

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6666

#define PRE_SIZE 3

#define USER_MAX 32

#define MESSAGE_MAX 999

#define USER_MESSAGE_MAX MESSAGE_MAX - USER_MAX - 1

#define HEARTBEAT 0
#define HEARTBEAT_STR '0'
#define HEARTBEAT_CLIENT_TIME 10
#define HEARTBEAT_SERVER_TIME HEARTBEAT_CLIENT_TIME * 2

#define REQUEST 1
#define REQUEST_STR '1'

#define RESPONSE 2
#define RESPONSE_STR '2'

#endif
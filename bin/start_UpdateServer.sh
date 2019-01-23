

# ----------------------------------------------------
# Stop script for the Socekt Server
# ----------------------------------------------------
#!/bin/sh

ps -ef | grep UpdateServer | grep -v grep
if [ $? -eq 0 ];then
  	PID_1024=$(echo `netstat -apn |grep 1024 | awk '{print $NF}'|awk -F '/' '{print $1}'`) 
  	kill  $PID_1024   
  	echo 'Kill UpdateServer' 
fi

nohup ./UpdateServer 10000 &
echo 'Start UpdateServer finish!'

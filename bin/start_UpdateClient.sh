# ----------------------------------------------------
# Stop script for the Socekt Server
# ----------------------------------------------------
#!/bin/sh

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/root/UpdateClient/output/lib
ps -ef | grep UpdateClient | grep -v grep
if [ $? -eq 0 ];then
  	PID_1024=$(echo `netstat -apn |grep 1024 | awk '{print $NF}'|awk -F '/' '{print $1}'`) 
  	kill  $PID_1024   
  	echo 'Kill UpdateClient'
fi

nohup ./UpdateClient 10000 &
echo 'Start UpdateClient finish!'

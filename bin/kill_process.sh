echo "begin kill_process"


	process_id=$(ps -ef | grep main | grep -v "grep" | awk '{print $2}')
	
	while [ ! -z "$process_id" ] ; do

		kill -9 $process_id
		process_id=$(ps -ef | grep main | grep -v "grep" | awk '{print $2}')
	done

echo "end kill_process"

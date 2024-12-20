if [ -z "$1" ]; then
    echo "Usage: $0 username"
    exit 1
fi

user_info=$(who | grep "^$1" | head -n 1)

if [ -n "$user_info" ]; then
    login_time=$(echo "$user_info" | awk '{print $3, $4}')
    current_time=$(date '+%Y-%m-%d %H:%M')
    echo "User $1 logged in at : $login_time"
    echo "Current time : $current_time"

    start_time=$(date -d "$login_time" +%s)
    end_time=$(date -d "$current_time" +%s)
    duration=$((end_time - start_time))
    echo "User $1 has been working for $(($duration / 3600)) hours and $((($duration % 3600) / 60)) minutes"
else
    echo "User $1 is not currently logged in"
fi


for i in *.FNT ; do
    j=`echo "$i" | sed 's/\.FNT/\.PNG/'`
    cat <<EOF
$i  
![ $i ]( images/$j )  

EOF
done

ford_fulkerson=./ford-fulkerson.bin


echo "Testando algoritmo Ford-Fulkerson"
for i in instances_ff/*.dat
do
	echo -e "\e[33mInstância $i\e[0m";
	val=$($ford_fulkerson -f $i);
	correto=$(grep $i gabarito_ff.txt | cut -d ' ' -f 2);
	[ $val -eq $correto ] && echo -e "Fluxo \e[32mOK\e[0m" || echo  -e "\e[31mFluxo incorreto\e[0m";


done

echo -e "\n\n";
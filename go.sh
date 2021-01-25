cd GetNextLine/
cp * ../GNL_lover/copy_in_here_GNL_files/
cp * ../gnlkiller/
cp * ..
cd ..

clear
mkdir get_next_line
cd GetNextLine/
cp * ../get_next_line
cd ..
cd gnl_unit_tests/
sh run_tests.sh
sh run_tests.sh bonus
sh run_tests.sh malloc
cd ..

clear
cd gnlkiller/
./run.sh
cd ..

clear
cd 42cursus_gnl_tests/
make GET_NEXT_LINE_FOLDER="../GetNextLine/"
cd ..

clear
cd 42TESTERS-GNL/
bash all_tests_with_bonus.sh
cd ..


clear
cd Get_Next_Line_Tester/
bash run.sh
cd ..

clear
cd GNL_lover/
./GNL_lover.sh

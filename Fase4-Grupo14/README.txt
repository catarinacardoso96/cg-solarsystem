Generator:
para criar executavel do programa correr na linha de comandos:
>g++ -o Generator main.cpp figures.cpp bezier.cpp aux_func.cpp

>Generator.exe plane (X) (Z) (nr divisões) (nome do ficheiro)

>Generator.exe box (X) (Y) (Z) (nr divisões) (nome do ficheiro)

>Generator.exe sphere (raio) (nr slices) (nr stacks) (nome do ficheiro)

>Generator.exe cone (raio) (altura) (nr slices) (nr stacks) (nome do ficheiro)

>Generator.exe cylinder (raio da base) (raio do topo) (altura) (nr slices) (nr stacks) (nome do ficheiro)

>Generator.exe torus (raio interior) (raio exterior) (nr sides) (nr rings) (nome do ficheiro)

>Generator.exe ellipsoid (X) (Y) (Z) (nr slices) (nr stacks) (nome do ficheiro)

>Generator.exe crown (raio interior) (raio exterior) (nr slices) (nome do ficheiro)

>Generator.exe belt (nr de esferas) (raio das esferas) (nr slices) (nr stacks) (raio interior) (raio exterior) (nome do ficheiro)

>Generator.exe bezier (tesselation level) (ficheiro.patch) (nome do ficheiro)


Engine:
Executar o CMake na pasta Engine
Compilar no VS
para executar:
Engine.exe xmlfile.xml

Unix-Engine:
cmake-gui &
make Engine
./Engine xmlfile.xml


Exemplos:
2 ficheiros .xml

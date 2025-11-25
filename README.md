# ☀️ Flower-Transport-the-Will-of-the-Moon 🌑

## Sobre o jogo

Acompanhe um grupo seleto de aventureiros que estão transportando uma carga misteriosa

Faça as melhores escolhas de ataques para poder ser capaz de derrotar o chefe em uma batalha árdua e aterrorizante

## Gameplay

O jogo se trata de uma batalha contra um grande chefe por turno, na qual o jogador controla as ações de 4 aventureiros

O jogador pode atacar, usar flores diurnas ou noturnas dependendo do personagem e defender

Ao selecionar o que deseja fazer, o jogador precisa acertar o coração do chefe para poder efetivar seu ataque

Cada ataque possui seu dano, seu elemento e sua velocidade, então o jogador precisa planejar com cuidado seus passos para poder derrotar o grande inimigo e ganhar sua pontuação final

# Comandos

Z = Confirmar escolha

X =  Retornar para escolha anterior (depende de onde você está no jogo)

UP_ARROW = Move para opção superior

DOWN_ARROW = Move para opção inferior

RIGHT_ARROW = Move para opção na direita

LEFT_ARROW = Move para opção na esquerda

### Instalação
   ```bash 
   

       # Windows
       
       Instale a biblioteca raylib em https://www.raylib.com
       
       Instale também a pasta raylib-5.0_win64_mingw-w64 
       (Pode diferenciar de computador para computador)
       Descompacte e coloque ela dentro da pasta raylib no disco local
       
       Crie os arquivos c_cpp_properties
       launch e tasks numa pasta .vscode
       
       Adicione uma condicional para checar o sistema operacional para acessar a biblioteca raylib para compilação
       
       Instale o make usando choco install make dentro do Windows Powershell
       
       Crie uma condicional no arquivo MAKEFILE para reconhecer que o sistema operacional usado é Windows e coloque os caminhos para a pasta nele
       
       Va para o bash dentro da pasta clonada no github e cole o comando export PATH="/c/raylib/w64devkit/bin:$PATH" e rode make run no terminal
       
       # Linux
       
       Comece entrando no terminal de comandos do Linux e rode esses comandos em ordem
       
       sudo apt install build-essential git
       sudo apt update
       sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
       
       Para instalar a raylib e configurá-la:
       
       git clone raylib
       cd raylib/src
        make PLATFORM=PLATFORM_DESKTOP 
       sudo make install 
       
       Após isso, clone o projeto:
       
       git clone https://github.com/AnzinFelipe/Flower-Transport-the-Will-of-the-Moon.git
       cd Flower-Transport-the-Will-of-the-Moon
       code .
       
       Abra um terminal e rode make run

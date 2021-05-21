# software_basico
Relação de arquivos criados nas aulas da disciplina Programação de software Básico.

# Configurações
===
* Configurações Porta Serial
emulador de duas portas seriais interligadas no Linux via socat:
"sudo apt-get install socat" - Instalar o socat.
"socat -d -d pty,raw,echo=0 pty,raw,echo=0" - Executar o emulador.
"cat < /dev/pts/3" - escuta a porta 3.
"echo "@" > /dev/pts/6" - Escreve na porta 6.

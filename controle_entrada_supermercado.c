    Funcionalidade: Programa para lê a o sinal enviado pelo leitor de temperatura via porta serial. 
    Descrição: Um supermercado precisa controlar o ingresso de clientes, pois não pode ser autorizada a entrada de pessoas com 	temperatura elevada (indicativo de febre), por determinação da 	Secretaria Municipal de Vigilância Sanitária, visando controlar a 	propagação da doença respiratória que assola a cidade, sabendo-se que a febre é um dos sintomas dessa doença. A Vigilância Sanitária também determinou o controle de lotação máxima, que não pode ultrapassar 50% da capacidade da loja. O supermercado adquiriu leitores de temperatura manuais, com programação para sinalizar a uma determinada temperatura. Entretanto, esses aparelhos e a operação se revelaram inadequados, devido à lentidão e formação de filas no ingresso à loja, provocando aglomeração. Contudo, os leitores possuem uma porta serial RS232 que permite tanto o acionamento do leitor quanto a leitura da temperatura por sistemas automatizados. Por isso, o gerente do supermercado solicitou ao Setor de Engenharia que usasse os leitores para automatizar o ingresso de clientes. Ele pediu um sistema que apenas autorizasse, ou não, a entrada de um cliente e fizesse a contagem de ingressantes. O engenheiro consultou o manual do aparelho e percebeu que a sua operação é bem simples. Ele (o aparelho) aciona o leitor ao receber um sinal no pino 2, da porta RS232, e envia um sinal, via pino 3, quando a temperatura configurada é atingida ou ultrapassada.
        
    Três problemas a resolver:
        1. Contar a quantidade de ingressantes;
        2. Liberar entrada de clientes; e
        3. Proibir a entrada de clientes.

        // Rotina para Proibir a entrada de clientes.
        char dado;  // 0b 01000100   0b11111111 0b01000000
        while (1)
        {
            LePorta(dado)   // Dados é um byte. 0B00000000
            if (dado != 0)
            {
              filtrar = dado & 0b01000000

              dado     = 'D';
                         01000100 & 
                         01000000
                         --------
              filtrar =  01000000  = '@'     
 
              dado     = '*';
                         00101010 & 
                         01000000
                         --------
             filtrar =  00000000 = '0'  
 
            e                       -->  &
            ou                      -->  |
            não                     -->  ~    
            Deslocamento a direita  -->  >>
            Deslocamento a esquerda -->  <<  

            Se dado = '@' Então   // pino 3 é um bit do byte lido.
                Escreva("Entrada Proibida!")
            Fim Se.
        }

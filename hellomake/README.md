# Sem Makefile

## Compilação e execução
<p>gcc -o hello hellomake.c hellofunc.c -I. </p>
<p>./hello</p>

## Observações
<ul>
    <li>'-I.' garante a analise do diretorio atual, localiza '.h'</li>
</ul>

# Makefile v1

## Compilação e execução
<p>make -f makefile1</p>
<p>./hellomake</p>

## Versão 1
<ul>
    <li>O programa Make sabe que a regra <em>hellomake</em> precisa ser executada se algum dos arquivos da primeira linha (apos o ':') for modificado.</li>
<ul>

## Versão 2
<ul>
    <li>Macro CC usada para definir compilador e macro CFLAGS para comando de compilação</li>
    <li>Ao colocar os arquivos objeto 'hellomake.o' e 'hellofunc.o' o Make compila as versões '.c' e, em seguida, constrói o executável.</li>
</ul>

## Versão 3
<ul>
    <li>A macro DEPS informa que na compilação o arquivo '.h' é necessario para compilação dos arquivos '.c'</li>
    <li>A regra informa, também, que os arquivos '.o' dependem da versão do arquivo '.c' e do '.h' (incluido na DEPS)</li>
</ul>
<ul>Definições:
    <li>O '-c' representa gerar o arquivo de objeto</li>
    <li>os comandos '-o $@' representam colocar a sadia da compilação no arquivo nomeado no lado esquerdo do ':'</li>
    <li>os simbolos '$<' é o primeiro item da lista de dependências (DEPS)</li>
    <li>CFLAGS é o macro definido com as opções das FLAGS</li>
</ul>
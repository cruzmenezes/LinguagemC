# Desafio de Projeto: Desenvolvendo um Projeto com o Paradigma de Programação Orientado à Aspectos

Neste projeto temos como proposta a implementação de uma solução envolvendo o Paradigma de Programação Orientado a Aspectos. Para que isso seja possível, é aconselhável trabalhar com um paradigma de programação primário para o projeto principal, como por exemplo, o paradigma Orientado a Objetos.

A proposta envolve criar uma função transversal ao código sendo aplicada em diferentes chamadas, no entanto, todas para o mesmo objetivo. Como exemplo de projeto de base podemos utilizar o seguinte problema:

Problema padrão: Em um sistema bancário, o cliente pode optar por fazer saques em diferentes contas (corrente, salário, poupança, investimento), no entanto, uma mensagem deve ser gerada informando caso o saldo seja insuficiente perante o valor requisitado. Essa mensagem deve ser gerada por meio de um log de erro envolvendo todas as contas, ou seja, todas as contas devem ser verificadas antes de liberar o dinheiro, analisando a disponibilidade do mesmo e, caso não seja possível, uma mensagem de saldo insuficiente deve ser gerada.

O programa principal implementando em Paradigma Orientado a Objetos deve abordar as funções básicas da conta bancária, já a verificação de saldo, por estar presente em todas a contas, deve ser implementado em Paradigma Orientado a Aspectos. Pode ser utilizada a linguagem Java com extensão da linguagem para aspectos “AspectJ”.


        public class ContaBancaria {
    private String tipoConta;
    private double saldo;

    public ContaBancaria(String tipoConta, double saldo) {
        this.tipoConta = tipoConta;
        this.saldo = saldo;
    }

    public String getTipoConta() {
        return tipoConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
            System.out.println("Saque de R$" + valor + " realizado na conta " + tipoConta);
        } else {
            System.out.println("Saldo insuficiente na conta " + tipoConta);
        }
    }
}

///////////////////////////////////

public class SistemaBancario {
    public static void main(String[] args) {
        ContaBancaria contaCorrente = new ContaBancaria("corrente", 1000.0);
        ContaBancaria contaSalario = new ContaBancaria("salário", 500.0);
        ContaBancaria contaPoupanca = new ContaBancaria("poupança", 2000.0);
        ContaBancaria contaInvestimento = new ContaBancaria("investimento", 3000.0);

        contaCorrente.sacar(500.0);
        contaSalario.sacar(700.0);
        contaPoupanca.sacar(2500.0);
        contaInvestimento.sacar(4000.0);
    }
}

//////////////////////////////


public aspect AspectVerificacaoSaldo {
    pointcut verificarSaldo(ContaBancaria conta, double valor):
        execution(void ContaBancaria.sacar(double)) && target(conta) && args(valor);

    before(ContaBancaria conta, double valor): verificarSaldo(conta, valor) {
        if (valor > conta.getSaldo()) {
            System.out.println("Saldo insuficiente na conta " + conta.getTipoConta());
        }
    }
}

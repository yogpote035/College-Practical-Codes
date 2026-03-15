pragma solidity ^0.8.0;

contract SimpleBank {

    uint private balance;
    uint private feeCollected;
    uint private feePercent = 2; // 2% transaction fee

    // Deposit money
    function deposit(uint amount) public {
        balance += amount;
    }

    // Withdraw money with transaction fee
    function withdraw(uint amount) public {

        uint fee = (amount * feePercent) / 100;

        require(balance >= amount + fee, "Insufficient balance");

        balance -= (amount + fee);
        feeCollected += fee;
    }

    // Check balance
    function getBalance() public view returns(uint){
        return balance;
    }
}
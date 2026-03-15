// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract OnlineShopping {

    struct Order {
        uint orderId;
        string productName;
        uint quantity;
        uint price;
    }

    mapping(uint => Order) private orders;

    // Store order details
    function addOrder(uint _orderId, string memory _productName, uint _quantity, uint _price) public {
        orders[_orderId] = Order(_orderId, _productName, _quantity, _price);
    }

    // Retrieve order details
    function getOrder(uint _orderId) public view returns(uint, string memory, uint, uint) {
        Order memory o = orders[_orderId];
        return (o.orderId, o.productName, o.quantity, o.price);
    }
}
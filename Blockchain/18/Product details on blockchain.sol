// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ProductStorage {

    struct Product {
        uint id;
        string name;
        uint price;
        uint quantity;
    }

    mapping(uint => Product) private products;

    // Store product details
    function addProduct(uint _id, string memory _name, uint _price, uint _quantity) public {
        products[_id] = Product(_id, _name, _price, _quantity);
    }

    // Retrieve product details
    function getProduct(uint _id) public view returns(uint, string memory, uint, uint) {
        Product memory p = products[_id];
        return (p.id, p.name, p.price, p.quantity);
    }
}
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract CertificateStorage {

    struct Certificate {
        string studentName;
        string course;
        string university;
        uint year;
    }

    mapping(string => Certificate) private certificates;

    // Store certificate information
    function addCertificate(
        string memory hash,
        string memory studentName,
        string memory course,
        string memory university,
        uint year
    ) public {

        certificates[hash] = Certificate(studentName, course, university, year);
    }

    // Retrieve certificate information using hash
    function getCertificate(string memory hash)
    public view returns(string memory, string memory, string memory, uint)
    {
        Certificate memory c = certificates[hash];
        return (c.studentName, c.course, c.university, c.year);
    }
}
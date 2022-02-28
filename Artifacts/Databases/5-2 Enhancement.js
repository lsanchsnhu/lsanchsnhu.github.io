var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/hr";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("hr");

  var firstPerson = { firstName: "Jack", lastName: "Smith", gender: "M", age: 45};
  dbo.collection("person").insertOne(firstPerson, function(err, res) {
    if (err) throw err;
  });

  var firstDepartment = { deptName: "Engineering", building: "Building 5"};
  dbo.collection("department").insertOne(firstDepartment, function(err, res) {
    if (err) throw err;
  });

  var firstPersonQuery = {$and:[{"firstName":"Luc"},{"lastName": "Sanchez"}]};
  let firstPersonResult;
  dbo.collection("person").find(firstPersonQuery, { projection: { _id: 1 } }).toArray(function(err, result) {
    if (err) throw err;
    firstPersonResult = result;
  });

  var firstDepartmentQuery = {$and:[{"deptName":"Computer Science"},{"building": "Mudd"}]};
  let firstDepartmentResult;
  dbo.collection("department").find(firstDepartmentQuery, { projection: { _id: {"$toString": "$_id"} } }).toArray(function(err, result) {
    if (err) throw err;
    firstDepartmentResult = result;    
  });

  var firstPersonDepartment = { personId: firstPersonResult, departmentId: firstDepartmentResult}
  dbo.collection("personDepartment").insertOne(firstPersonDepartment, function(err, res) {
    if (err) throw err;
  });

  var secondPerson = { firstName: "Luc", lastName: "Sanchez", gender: "M", age: 30, favBook: "The Dark Tower"};
  dbo.collection("person").insertOne(secondPerson, function(err, res) {
    if (err) throw err;
  });

  var secondDepartment = { deptName: "Computer Science", building: "Mudd"};
  dbo.collection("department").insertOne(secondDepartment, function(err, res) {
    if (err) throw err;
  });

  var secondPersonQuery = {$and:[{"firstName":"Luc"},{"lastName": "Sanchez"}]};
  let secondPersonResult;
  dbo.collection("person").find(secondPersonQuery, { projection: { _id: 1 } }).toArray(function(err, result) {
    if (err) throw err;
    secondPersonResult = result;
  });

  var secondDepartmentQuery = {$and:[{"deptName":"Computer Science"},{"building": "Mudd"}]};
  let secondDepartmentResult;
  dbo.collection("department").find(secondDepartmentQuery, { projection: { _id: {"$toString": "$_id"} } }).toArray(function(err, result) {
    if (err) throw err;
    secondDepartmentResult = result;    
  });

  var secondPersonDepartment = { personId: secondPersonResult, departmentId: secondDepartmentResult}
  dbo.collection("personDepartment").insertOne(secondPersonDepartment, function(err, res) {
    if (err) throw err;
    db.close();
  });

});
function calc($scope) {
  
  $scope.a = 0;
  $scope.b = 0;
  $scope.operation = '+';
  
  $scope.na = function() {
    return $scope.a - 0;
  }
  
  $scope.nb = function() {
    return $scope.b - 0;
  }
  
  $scope.calculate = function() {
    if($scope.operation == '+') {
      return $scope.na() + $scope.nb();
    }
    if($scope.operation == '-') {
      return $scope.a - $scope.b;
    }
    if($scope.operation == '*') {
      return $scope.a * $scope.b;
    }
    if($scope.operation == '/') {
      return $scope.a / $scope.b;
    }
    return "undef";
  }
}

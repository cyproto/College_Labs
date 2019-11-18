<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
		<link rel="stylesheet" href="login.css" type="text/css">
		<meta charset="ISO-8859-1">
		<title>Login</title>
	</head>
<body>
	<form class="col-md-12" action="<%=request.getContextPath()%>/login" method="post">
            <div class="center_class formborder">
                <h2>Login.</h2>
                    <div class="form-group">
                        <input type="text" id="username" placeholder="Username" name="username" class="form-control">
                    </div>
                    <div class="form-group">
                        <input type="password" placeholder="Password" name="password" class="form-control">
                    </div>
                    <div class="form-group buttons">
                        <input type="submit" value="Log In" class="btn btn-success">
                        <input type="reset" value="Reset" class="btn btn-primary">
                    </div>
            </div>
        </form>
	</body>
</html>
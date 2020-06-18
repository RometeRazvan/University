function validate() {
	
	var nume = document.getElementById('nume');
	var data = document.getElementById('data');
	var varsta = document.getElementById('varsta');
	var email = document.getElementById('email');
	
	var litere = /^[A-Za-z ]+$/;
	var numere = /^[1-9][0-9]*$/;
	var emailRegex = /^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
	var dateRegex = /^([0-2][0-9]|(3)[0-1])(\/)(((0)[0-9])|((1)[0-2]))(\/)\d{4}$/;
	
	var exceptionStr = "Urmatoarele campuri sunt invalide: ";
	var exception = exceptionStr;
	
	var out = document.getElementById("rezultat");
	
	var borderStyle = "border: 3px; border-style: solid; border-color: red;";
	
	nume.style = ""; data.style = ""; varsta.style = ""; email.style = ""; 
	
	if(!nume.value.match(litere)) {
		exception += "nume";
		nume.style = borderStyle;
	}
	
	if(!data.value.match(dateRegex)) {
		if(exception == exceptionStr) exception += "data";
		else exception += ", data ";
		data.style = borderStyle;
	}
	
	if(!varsta.value.match(numere)){
		if(exception == exceptionStr) exception += "varsta";
		else exception += ", varsta ";
		varsta.style = borderStyle;
	}
	
	if(!email.value.match(emailRegex)) {
		if(exception == exceptionStr) exception += "email";
		else exception += ", email ";
		email.style = borderStyle;
	}
	
	if(exception != exceptionStr)
		out.innerHTML = exception;
	else out.innerHTML = "Datele sunt corecte";
}

document.getElementById('trimite').addEventListener('click', validate);
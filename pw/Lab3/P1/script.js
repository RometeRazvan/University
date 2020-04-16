function move() {
	
	var moveTo = this.parentElement.id == "lista1" ? lista2 : lista1;
	
	moveTo.appendChild(this);
	
}

function run() {
	
	var lista1 = document.getElementById("lista1");
	var lista2 = document.getElementById("lista2");
	
	for(var i = 0 ; i < lista1.length; ++i)
		lista1[i].addEventListener('dblclick', move);
	
	for(var i = 0 ; i < lista2.length; ++i)
		lista2[i].addEventListener('dblclick', move);
}

run();
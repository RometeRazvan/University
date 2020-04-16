var nrTurned = 0;
var otherChild;

function revert() {
	var child = this.children[0];
	
	var hide = "font-size: 60px; display: none;";
	var reveal = "font-size: 60px; display: block;";
	
	child.style = reveal;
	
	if(nrTurned == 0) {
		otherChild = child;
		nrTurned = 1;
	}
	else if(nrTurned == 1) {
			nrTurned = 0;
			if(child.innerHTML != otherChild.innerHTML) {
				
				setTimeout(function(){ 
				child.style = hide;
				otherChild.style = hide; 
				}, 1000);
				
			}
		}
}

function main() {
	
	var cells = document.getElementsByClassName("cell");
	var tableCells = document.getElementsByClassName("tableCell");
	
	for(var tableCell of tableCells) {
		tableCell.style = "padding: 20px; height: 100px; width: 100px; text-align: center;";
		tableCell.onclick = revert;
	}

	for(var cell of cells) {
		cell.style = "font-size: 60px; display: none;";
	}
	
}

main();
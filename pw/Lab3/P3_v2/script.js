var nrTurned = 0;
var otherChild;

function revert() {
	var child = this.children[0];
	
	var hide = "height: 100px; width: 100px;display: none;";
	var reveal = "height: 100px; width: 100px;display: block;";
	
	child.style = reveal;
	
	if(nrTurned == 0) {
		otherChild = child;
		nrTurned = 1;
		return;
	}
	else if(nrTurned == 1) {
			nrTurned = 0;
			if(child.src != otherChild.src) {
				
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
		tableCell.style = "padding: 20px; height: 100px; width: 100px;";
		tableCell.onclick = revert;
	}

	for(var cell of cells) {
		cell.style = "height: 100px; width: 100px;display: none;";
	}
	
}

main();
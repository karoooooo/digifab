function hideMenu (){
 const hamburger = document.getElementById("nav-list");

 if(hamburger.style.display === "flex"){
  hamburger.style.display = "none";
 } else {
  hamburger.style.display = "flex";
 }
}


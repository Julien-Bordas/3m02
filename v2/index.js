function tab(event, tab) {
    let tabs = document.getElementsByClassName("tab");
    for (i = 0; i < tabs.length; i++) {
        if(tabs[i].id != tab) {
            tabs[i].dataset.active = "inactive"
        } else {
            tabs[i].dataset.active = "active"
        }
    }

    let buttons = document.getElementsByClassName("tab-select");
    for (i = 0; i < buttons.length; i++) {
        buttons[i].dataset.active = "inactive"
    }

    event.currentTarget.dataset.active = "active";
}

function fonction1() {
  var R1_pos_odom_X = document.getElementById("R1_pos_odom_X_newvalue").value;
  console.log(R1_pos_odom_X);
  document.getElementById("R1_pos_odom_X").innerHTML = R1_pos_odom_X;
}

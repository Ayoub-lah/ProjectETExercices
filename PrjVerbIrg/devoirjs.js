var verbs = [
    ["abide", "abode", "abode", "demeurer"],
    ["awake", "awoke", "awoken", "(se) réveiller, aussi awake/awoke/awoke"],
    ["be", "was/were", "been", "être"],
    ["bear", "bore", "borne", "porter/supporter/soutenir"],
    ["beat", "beat", "beaten", "battre"],
    ["become", "became", "become", "become"],
    ["beget", "begat", "begotten", "engendrer, aussi beget/begot/begotten"],
    ["begin", "began", "begun", "commencer"],
    ["bend", "bent", "bent", "se courber, etc."],
    ["bereave", "bereft", "bereft", "déposséder/priver"],
    ["bring", "brought", "brought", "apporter"],
    ["build", "built", "built", "varruire"],
    ["burn", "burnt", "burnt", "brûler"],
    ["burst", "burst", "burst", "éclater"],
    ["buy", "bought", "", "acheter"],
    ["cast", "cast", "cast", "jeter, etc."],
    ["catch", "caught", "caught", "attraper"],
    ["chide", "chid", "chidden", "gronder/réprimander, aussi chide/chid/chid"],
    ["choose", "chose", "chosen", "choisir"],
    ["cleave", "cleft", "cleft", "fendre/coller, aussi cleave/clove/clove"],
    ["cling", "clung", "clung", "se cramponner"],
    ["come", "came", "come", "venir"],
    ["cost", "cost", "cost", "coûter"],
    ["creep", "crept", "crept", "ramper/se glisser/se hérisser"],
    ["crow", "crew", "crowed", "chanter (un coq)/jubiler"],
    ["cut", "cut", "cut", "couper"],
    ["deal", "dealt", "dealt", "distribuer/traiter"],
    ["dig", "dug", "dug", "bêcher"],
    ["do", "did", "", "faire"],
    ["draw", "drew", "drawn", "tirer/dessiner"],
    ["dream", "dreamt", "dreamt", "rêver"],
    ["drink", "drank", "drunk", "boire"],
    ["drive", "drove", "driven", "conduire"],
    ["dwell", "dwelt", "dwelt", "habiter/rester"],
    ["eat", "ate", "eaten", "manger"],
    ["fall", "fell", "fallen", "tomber"],
    ["feed", "fed", "fed", "nourrir"],
    ["feel", "felt", "felt", "(se) sentir"],
    ["fight", "fought", "fought", "combattre"],
    ["find", "found", "found", "trouver"],
];
    
    var tableBody = document.querySelector("#verbsTable tbody");
    var lettersList = document.querySelector("#letterLinks");
    var addVerbBtn = document.querySelector("#addVerb");
    var findVerbBtn = document.querySelector("#findVerb");
    var toggleViewBtn = document.querySelector("#toggleView");
    var leftPane = document.querySelector("#leftPanel");
    var rightPane = document.querySelector("#rightPanel");
    var statsDetails = document.querySelector("#statsDetails");
    
    document.getElementById('btn1').addEventListener('click', function() {
        // Get references to the panels
        const leftPanel = document.getElementById('leftPanel');
        const rightPanel = document.getElementById('rightPanel');
        
        // Swap the inner HTML of the two panels
        const temp = leftPanel.innerHTML;
        leftPanel.innerHTML = rightPanel.innerHTML;
        rightPanel.innerHTML = temp;
    });
    

    function saveVerbsToLocalStorage() {
        localStorage.setItem("verbs", JSON.stringify(verbs));
    }
    
    function loadVerbsFromLocalStorage() {
        var storedVerbs = localStorage.getItem("verbs");
        if (storedVerbs) {
            verbs = JSON.parse(storedVerbs);
        }
    }

function addVerb() {
    var newRow = document.createElement("tr");
    newRow.innerHTML = `
        <td><input type="text" class="base-form" placeholder="Base form" required></td>
        <td><input type="text" class="past-tense" placeholder="Past tense" required></td>
        <td><input type="text" class="past-participle" placeholder="Past participle" required></td>
        <td><input type="text" class="translation" placeholder="Translation" required></td>
        <td>
            <button class="save-btn">Save</button>
            <button class="cancel-btn">Cancel</button>
        </td>
    `;
    tableBody.appendChild(newRow);
    newRow.querySelector(".save-btn").addEventListener("click", () => saveNewVerb(newRow));
    newRow.querySelector(".cancel-btn").addEventListener("click", () => cancelAddVerb(newRow));
}

function saveNewVerb(row) {
    var baseForm = row.querySelector(".base-form").value.trim();
    var pastTense = row.querySelector(".past-tense").value.trim();
    var pastParticiple = row.querySelector(".past-participle").value.trim();
    var translation = row.querySelector(".translation").value.trim();
    if (!baseForm) {
        alert("The 'Base form' field is required!");
        return;
    }
    let fields = row.querySelectorAll("input");
    fields.forEach(field => {
        if (!field.value.trim()) {
            field.style.border = "2px solid red";
        } else {
            field.style.border = ""; 
        }
    });
    if (!baseForm || !pastTense || !pastParticiple || !translation) {
        return;
    }
    verbs.push([baseForm, pastTense, pastParticiple, translation]);
    verbs.sort((a, b) => a[0].localeCompare(b[0])); 
    let firstLetter = baseForm[0].toLowerCase();
    if (!lettersList.querySelector(`li[data-letter="${firstLetter}"]`)) {
        var li = document.createElement("li");
        li.setAttribute("data-letter", firstLetter);
        li.innerHTML = `<a href="#">${firstLetter.toUpperCase()}</a>`;
        li.addEventListener("click", () => {
            filterByLetter(firstLetter);
            applyRowColors();
        });
        lettersList.appendChild(li);
    }
    saveVerbsToLocalStorage();
    loadVerbs();
}

function cancelAddVerb(row) {
    row.remove();
}


function saveNewVerb(row) {
    var baseForm = row.querySelector(".base-form").value.trim();
    var pastTense = row.querySelector(".past-tense").value.trim();
    var pastParticiple = row.querySelector(".past-participle").value.trim();
    var translation = row.querySelector(".translation").value.trim();
    if (!baseForm || !pastTense || !pastParticiple || !translation) {
        alert("All fields are required!");
        return;
    }
    verbs.push([baseForm, pastTense, pastParticiple, translation]);
    verbs.sort((a, b) => a[0].localeCompare(b[0])); 
    saveVerbsToLocalStorage();
    loadVerbs();
}

function cancelAddVerb(row) {
    row.remove();
}

function editVerb(index) {
    var row = tableBody.querySelectorAll("tr")[index];
    var cells = row.querySelectorAll("td");
    for (let i = 0; i < cells.length - 1; i++) {
        let currentValue = cells[i].textContent;
        cells[i].innerHTML = `<input type="text" value="${currentValue}" class="edit-input">`;
    }
    let actionCell = cells[cells.length - 1];
    actionCell.innerHTML = `
        <button class="save-btn" data-index="${index}">Save</button>
        <button class="cancel-btn" data-index="${index}">Cancel</button>
    `;
    attachSaveCancelEvents(index);
}

function attachSaveCancelEvents(index) {
    document.querySelector(`.save-btn[data-index="${index}"]`).addEventListener("click", () => updateVerb(index));
    document.querySelector(`.cancel-btn[data-index="${index}"]`).addEventListener("click", () => loadVerbs());
}

function updateVerb(index) {
    var row = tableBody.querySelectorAll("tr")[index];
    var cells = row.querySelectorAll("td");
    var updatedVerb = [];
    for (let i = 0; i < cells.length - 1; i++) {
        let input = cells[i].querySelector("input");
        if (!input.value) {
            alert("All fields are required!");
            return;
        }
        updatedVerb.push(input.value);
    }
    verbs[index + 1] = updatedVerb;
    loadVerbs();
    saveVerbsToLocalStorage();
}

function deleteVerb(index) {
    if (confirm("Are you sure you want to delete this verb?")) {
        verbs.splice(index + 1, 1);
        loadVerbs();
        saveVerbsToLocalStorage();
    }
}

document.getElementById("findVerb").addEventListener("click", function () {
    var searchQuery = document.getElementById("searchVerb").value.trim().toLowerCase();
    var rows = Array.from(document.querySelectorAll("#verbsTable tbody tr"));
    var foundRow = null;
    rows.some(row => {
        var baseForm = row.cells[0].textContent.toLowerCase();
        if (baseForm === searchQuery) {
            row.classList.add("highlight");
            foundRow = row;
            return true; 
        }
        return false;
    });
    if (foundRow) {
        var tableBody = document.querySelector("#verbsTable tbody");
        tableBody.insertBefore(foundRow, tableBody.firstChild);
        var leftPane = document.getElementById("leftPane");
        leftPane.scrollIntoView({ behavior: "smooth", block: "start" });
    } else {
        alert("Verb not found.");
    }
});

function attachButtonEvents() {
    document.querySelectorAll(".edit-btn").forEach((btn) => {
        btn.addEventListener("click", () => editVerb(parseInt(btn.dataset.index)));
    });
    document.querySelectorAll(".delete-btn").forEach((btn) => {
        btn.addEventListener("click", () => deleteVerb(parseInt(btn.dataset.index)));
    });
}

toggleViewBtn.addEventListener("click", () => {
    var mainContainer = document.querySelector("main");
    var leftPane = document.getElementById("leftPane");
    var rightPane = document.getElementById("rightPane");
    if (mainContainer.firstElementChild === leftPane) {
        mainContainer.appendChild(leftPane); 
        mainContainer.insertBefore(rightPane, leftPane); 
    } else {
        mainContainer.appendChild(rightPane); 
        mainContainer.insertBefore(leftPane, rightPane); 
    }
    var isLeftFirst = mainContainer.firstElementChild === leftPane;
    toggleViewBtn.textContent = isLeftFirst ? "◀ ▶" : "▶ ◀";
});

toggleViewBtn.addEventListener("click", () => {
    var isCollapsed = rightPane.style.display === "none";
    if (isCollapsed) {
        rightPane.style.display = "block";
        toggleViewBtn.textContent = "▶ ";
    } else {
        rightPane.style.display = "none";
        toggleViewBtn.textContent = "◀";
    }
});

addVerbBtn.addEventListener("click", addVerb);
findVerbBtn.addEventListener("click", findVerb);

loadVerbs();

function applyRowColors() {
    var rows = document.querySelectorAll("#li tbody tr");
    rows.forEach((row, index) => {
        if (index % 2 === 0) {
        row.style.backgroundColor = "#f9f9f9"; 
        } else {
            row.style.backgroundColor = "#ffe4b2"; 
    }
    });
}

function generateAlphabetLinks() {
    lettersList.innerHTML = ""; 
    var alphabet = "abcdefghijklmnopqrstuvwxyz".split("");
    alphabet.forEach(function(letter) {
        var letterVerbs = verbs.slice(1).filter(function(verb) {
        return verb[0].toLowerCase().startsWith(letter);
    });
    if (letterVerbs.length > 0) {
        var li = document.createElement("li");
        li.innerHTML = "Here is a link to <a href=\"#\">verbs that start with the letter " + letter + "</a>";
        li.addEventListener("click", function() {
            filterByLetter(letter);
            applyRowColors() ;
        });
        lettersList.appendChild(li);
    }
    });
}

function filterByLetter(letter) {
var filteredVerbs = verbs.slice(1).filter(function(verb) {
    return verb[0].toLowerCase().startsWith(letter);
});
tableBody.innerHTML = ""; 
filteredVerbs.forEach(function(verb, index) {
    var row = document.createElement("tr");
    row.innerHTML = "<td>" + verb[0] + "</td>" +
                    "<td>" + verb[1] + "</td>" +
                    "<td>" + verb[2] + "</td>" +
                    "<td>" + verb[3] + "</td>" +
                    "<td>" +
                        '<button class="edit-btn" data-index="' + index + '">Edit</button>' +
                        '<button class="delete-btn" data-index="' + index + '">Delete</button>' +
                    "</td>";
    tableBody.appendChild(row);
});
attachButtonEvents(); 
}

function updateStatistics() {
                var counts = {};
                verbs.slice(1).forEach(verb => {
                    var letter = verb[0][0].toUpperCase();
                    counts[letter] = (counts[letter] || 0) + 1;
                });
                statsDetails.textContent = Object.entries(counts)
                    .map(([letter, count]) => `${letter} - ${count}`)
                    .join(", ");
}

function applyRowColors() {
    var rows = document.querySelectorAll("#verbsTable tbody tr");
    rows.forEach((row, index) => {
        if (index % 2 === 0) {
        row.style.backgroundColor = "#f9f9f9"; 
        row.style.backgroundColor = "#ffe4b2"; 
        }
    });
}

function loadVerbs() {
    tableBody.innerHTML = ""; 
    verbs.slice(1).forEach((verb, index) => {
        var row = document.createElement("tr");
        row.innerHTML =
        "<td>" + verb[0] + "</td>" +
        "<td>" + verb[1] + "</td>" +
        "<td>" + verb[2] + "</td>" +
        "<td>" + verb[3] + "</td>" +
        "<td>" +
        '<button class="edit-btn" data-index="' + index + '">Edit</button>' +
        '<button class="delete-btn" data-index="' + index + '">Delete</button>' +
        "</td>";
        tableBody.appendChild(row);
    });
    attachButtonEvents(); 
    applyRowColors();
}

loadVerbsFromLocalStorage();
loadVerbs();
generateAlphabetLinks();
updateStatistics() ;

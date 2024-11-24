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
    var leftPane = document.querySelector("#lleftPanel");
    var rightPane = document.querySelector("#rightPanel");
    var statsDetails = document.querySelector("#statsDetails");

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
    var baseForm = prompt("Enter the base form:");
    var pastTense = prompt("Enter the past tense:");
    var pastParticiple = prompt("Enter the past participle:");
    var translation = prompt("Enter the translation:");

    if (!baseForm || !pastTense || !pastParticiple || !translation) {
    alert("All fields are required!");
    return;
    }
    verbs.push([baseForm, pastTense, pastParticiple, translation]);
    verbs.sort((a, b) => a[0].localeCompare(b[0])); 
    loadVerbs();
    saveVerbsToLocalStorage();
    
}

function editVerb(index) {
    var verb = verbs[index + 1]; 
    var newBaseForm = prompt("Edit the base form:", verb[0]);
    var newPastTense = prompt("Edit the past tense:", verb[1]);
    var newPastParticiple = prompt("Edit the past participle:", verb[2]);
    var newTranslation = prompt("Edit the translation:", verb[3]);

    if (newBaseForm && newPastTense && newPastParticiple && newTranslation) {
    verbs[index + 1] = [newBaseForm, newPastTense, newPastParticiple, newTranslation];
    loadVerbs();
    saveVerbsToLocalStorage();
    }else {
        alert("All fields are required!");
    }
}

function updateVerb(index) {
    editVerb(index); 
}

function deleteVerb(index) {
    if (confirm("Are you sure you want to delete this verb?")) {
    verbs.splice(index + 1, 1); 
    loadVerbs();
    saveVerbsToLocalStorage();
    }
}

function findVerb() {
    var searchQuery = prompt("Enter a verb to find:");
    if (!searchQuery) return;

    var foundIndex = verbs.findIndex(
    (verb, idx) => idx > 0 && verb[0].toLowerCase() === searchQuery.toLowerCase()
    );

    if (foundIndex > -1) {
        var rows = tableBody.querySelectorAll("tr");
        rows[foundIndex - 1].classList.add("red-border");
        alert("Found: " + verbs[foundIndex].join(", "));
    } else {
        alert("Verb not found.");
    }
}

function attachButtonEvents() {
    document.querySelectorAll(".edit-btn").forEach((btn) => {
        btn.addEventListener("click", () => editVerb(parseInt(btn.dataset.index)));
    });

    document.querySelectorAll(".update-btn").forEach((btn) => {
        btn.addEventListener("click", () => updateVerb(parseInt(btn.dataset.index)));
    });

    document.querySelectorAll(".delete-btn").forEach((btn) => {
        btn.addEventListener("click", () => deleteVerb(parseInt(btn.dataset.index)));
    });
}

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
                        '<button class="update-btn" data-index="' + index + '">Update</button>' +
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
        '<button class="update-btn" data-index="' + index + '">Update</button>' +
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

const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <title>Document</title>
</head>
<style>

*{
    
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: "poppins";
    
}
body {
    width: 100%;
    height: auto;
    padding-top: 100px;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
    background: url("back.jpg");
    background-size: cover;
    background-repeat: no-repeat;
    background-position: center;
    

}
.container {
    top: calc(12% + 50px);
    height: 540px;
    width: 400px;
    background-color: #658faf;
    box-shadow: 0px 0px 10px rgba(0,0,0,.2);
    border-radius: 15px;
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column;
    overflow: hidden;
    position: fixed;
    transition: all 0.3s ease;
}
.main-content {
    display: none;
    justify-content: center;
    align-items: center;
    flex-direction: column;
    position: absolute; 
    top: 50%;
    left: 62%;
    transform: translate(-50%, -50%); 
}

.main-content.show {
    display: flex; 
    height: 680px;
    width: 400px;
}
.main-content.show .btn {
    width: 350px;
    height: 60px;
    display: flex; /* Flexbox kullanımı */
    justify-content: center; /* Yatayda ortalama */
    align-items: center; /* Dikeyde ortalama */
    margin-top: 50px;
    border-radius: 50px;
    border: none;
    outline: none;
    background: linear-gradient(45deg, #3873a3, 60%, #016699);
    font-size: 19px;
    font-weight: 500;
    color: #eee;
    position: relative;
    cursor: pointer;
    z-index: 1;
    overflow: hidden;
}

.success-message {
    margin: 30px;
    position: relative; /* Bu, içindeki h2'nin position: absolute; ile ortalanmasını sağlar */
}
.success-message h2 {
    
    margin-top: 70px;
    font-size: 32px;
    position: absolute; /* Üstteki relative konumuna göre ortalanacak */
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%); /* Elemanı tam olarak ortalar */
    color: #fff; 
}

.container.move-left {
    height: 88%;
    border-radius: 0px;
    box-shadow: none;
    top: calc(12%);
    left: 0;
    background-color: #4c80a7;
    transform: translate(0, 0);
    transition: all 0.3s ease;
}

.container.move-right {
    top: calc(50% + 50px);
    left: 50%;
    transform: translate(-50%, -50%);
    transition: all 0.3s ease;
}
.container.move-left .Form{
    margin-top: -180px;
    margin-bottom: -80px;
}



.Form{
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column;
    margin-top: -100px;
    margin-bottom: -80px;
    
    
}
.login-form{
    position: absolute;
    transform: translateX(0px);
    transition: .5s ease;

}

.login-form.active{
    transform: translateX(-410px);
}

h2{
    color: #fff;
    font-size: 32px;
    font-weight: bold;
    
}

.input-box{
    position: relative;
    width: 100%;
    height: 50px;
    margin: 40px 0;
    padding-block: 25px;
    
}

.input-box input{
    width: 100%;
    height: 100%;
    background: transparent;
    border: none;
    outline: none;
    border: 2px solid rgba(255,255,255,.2);
    border-radius:40px;
    font-size: 16px;
    color: #efefef;
    padding: 20px 45px 20px 20px;
}
.input-box label{
    position: absolute;
    left: 0;
    transform: translateY(-56%);
    font-size: 15px;
    font-weight: 500;
    padding: 20px 45px 15px 20px;
    color: #fff;
    margin-top: -15px;
    font-weight: 600;
}

input::placeholder{
    font-size: 13px;
    color:#ccc;
}
input#checked{
    margin-right: 3px;
}



header {
    position: fixed;
    top: 0;
    width: 100%;
    height: 12%;
    display: flex;
    justify-content: space-between;
    align-items: center;
    background-color: #4c80a7;
    box-shadow: 0px 0px 10px rgba(0,0,0,.2);
    

    padding: 0 20px;
}

header img {
    margin-left: 30px;
    height: 60px;
    width: 300px;
}

header label {
    font-size: 32px;
    font-weight: 600;
    color: #fff;
    text-align: center;
    flex: 1;
    margin-left: -140px; /* Adjust this value to fine-tune the centering */
}

.navheader {
    display: flex;
    align-items: center;
    margin-right: 20px;
    font-weight: 900;
}

.navdata {
    margin: 0 10px;
    text-align: center;
    color: #fff;
    font-weight: 900;
}

.navheading {
    font-size: 16px;
    color: #fff;
    font-weight: 900;
}


/* Further adjustments for mobile screens */
@media (max-width: 860px) {
    header {
        flex-direction: column;
        height: 12%;
        padding: 10px;
    }

    header img {
        margin: 0;
        height: 40px;
        width: 150px;
    }
    .navheader {
        display: none;
    }
    header label {
        margin-top: 10px;
        font-size: 20px;
        margin-left: 0;
    }

    .navheader {
        justify-content: center;
        margin-right: 0;
    }

    .container {
        width: 70%;
        height: 70%;
    }



    .container.move-left .Form {
        margin-top: 0px;  /* Ensure no negative margin */
        margin-bottom: 0px;  /* Adjust as needed */
        padding: 10px;  /* Add some padding to ensure spacing */
        display: flex;
        justify-content: flex-start;  /* Aligns the form to the top */
        align-items: center;
        flex-direction: column;
    }
    .burger-menu {
        display: block;
        position: fixed;
        top: 20px;
        right: 20px;
        width: 40px;
        height: 40px;
        background-color: #4c80a7;
        cursor: pointer;
        z-index: 1001;
    }

    .burger-menu span {
        display: block;
        width: 30px;
        height: 3px;
        background-color: #fff;
        margin: 6px auto;
    }
    /* When the menu is open */
    .container.move-left {
        width: 60%;
        height: calc(100% - 12%);
        /* Adjustments specific to the moved-left state can be added here */
    }
}














.btn{
    width: 100%;
    height: 40px;
    margin-top: 20px;
    border-radius: 50px;
    border: none;
    outline: none;
    background: linear-gradient(45deg ,#3873a3,60% ,#016699);
    font-size: 19px;
    font-weight: 500;
    color: #eee;
    position: relative;
    cursor: pointer;
    z-index: 1;
    overflow: hidden;
}
.btn::before{
    content: "";
    position: absolute;
    left: 0;
    top: 0%;
    height: 100%;
    width: 00%;
    background: linear-gradient(45deg, #3275a2, #10547e);
    transition: .4s ease;
    z-index: -1;
}
.btn:hover{
    color: #eee;
}
.btn:hover:before{
    width: 100%;
}

.float-container {
    max-height: 600px; 
    padding: 30px;
    padding-left: 98px;
    display: flex;
    flex-wrap: wrap; /* Allow blocks to wrap to the next line */
    gap: 10px; /* Space between blocks */
    overflow-y: auto; /* Enable vertical scrolling if content exceeds container height */
    margin-left: 380px;
    position: fixed; /* Fixed position */
    top: 110px; 
    box-sizing: border-box;
    justify-content: flex-start; /* Left-align blocks */
}
.container-title {
    font-size: 24px;
    font-weight: bold;
    margin-bottom: 20px;
    margin-top: 10px; /* Add some top margin */
    text-align: center;
    color: #ffffff;
    display: block; /* Ensure the title is treated as a block element */
    width: 100%; /* Ensure it takes the full width of the container */
    z-index: 10;
}


.float-child {
    margin: 8px;
    height: 130px;
    padding: 10px;
    box-sizing: border-box; 
    color: white;
    position: relative; 
    background-color: #658faf;
    box-shadow: 0px 0px 10px rgba(0,0,0,.2);
    border-radius: 15px;
    min-width: 300px; /* Ensure a minimum width */
    display: flex; /* Use Flexbox */
    flex-direction: column; /* Stack children vertically */
    justify-content: center; /* Center horizontally */
    align-items: center; /* Center vertically */
    overflow: hidden; /* Prevent content from overflowing */
    text-overflow: ellipsis; /* Adds ellipsis for overflowing text */
}

.device-id {
    position: absolute;
    top: 10px;
    left: 10px;
    font-size: 14px;
    font-weight: bold;
    color: #fff;
}

.central-text {
    flex: 1;
    display: flex;
    flex-direction: column; /* Stack text vertically */
    align-items: center;
    justify-content: center;
    font-size: 16px;
    color: #fff;
    text-align: center; /* Center align the text */
    line-height: 1.5; /* Improve readability */
}

.status {
    position: absolute;
    bottom: 10px;
    left: 10px;
    font-size: 12px;
    color: #fff;
    display: flex;
    align-items: center;
}

.status .spinner-container {
    display: flex;
    align-items: center;
}

.status .spinner {
    width: 8px; /* Adjust the size of the spinner */
    height: 8px; /* Adjust the size of the spinner */
    border-radius: 50%;
    background-color: #fff;
    margin: 0 4px; /* Increase spacing between spinners */
    animation: bounce 1.5s infinite ease-in-out;
}

@keyframes bounce {
    0%, 100% {
        transform: scale(1);
    }
    50% {
        transform: scale(1.5);
    }
}

@media (max-width: 768px) {
    .float-child {
        min-width: 200px; /* Adjust the minimum width for smaller screens */
    }
    
    .float-container {
        margin-left: 20px; /* Adjust margin for smaller screens */
    }
}



.page-title {
    font-size: 24px; /* Başlık boyutunu ayarlayın */
    color: #fff; /* Başlık rengini ayarlayın */
    font-weight: bold; /* Başlık metnini kalın yapın */

  
    position: absolute; /* Position it absolutely relative to .float-container */
    top: 105PX; /* Align at the top */
    left: 62.8%; /* Center horizontally */
    transform: translateX(-50%); /* Adjust to center horizontally */
    width: 200px; /* Ensure full width */
    text-align: center; /* Center text inside */
    align-items: center;
    justify-content: center;
}



</style>





<body onload="process()">
    <header>
        <img src="logo" alt="logo">
        <label>P2P Listen Mode</label>
        <div class="navheader">
            <div class="navdata">
                <div class="navheading">DATE</div>
                <div id="date">mm/dd/yyyy</div>
            </div>
            <div class="navdata">
                <div class="navheading">TIME</div>
                <div id="time">00:00:00</div>
            </div>
        </div>
    </header>
    
    <h1 class="page-title" id="selectedContainer" style="display: none;">Container</h1>
    
    <div id="settingsContainer" class="container">
        
        <div class="Form login-form">
        <h2>Settings</h2>
        <form action="#">
            <div class="input-box">
                <label for="#">P2P configuration</label>
                <i class='bx bxs-user'></i>
                <input id="field1" type="text" placeholder="868000000:7:125:0:8:22" required class>
            </div>
            <div class="input-box">
                <label for="#">Input Parameter (PRECV)</label>
                <input id="field2"type="text" placeholder="65534" required class>
            </div>
            <div class="input-box">
                <label for="#">Mahal No</label>    
                <input id="field3" type="text" required class>
            </div>  
            <button id="listenButton" type="submit" class="btn">Listen</button>
            <button id="stopButton" type="reset" class="btn" hidden>Stop</button>
            <button id="backButton" type="reset" class="btn" hidden>Back</button>
            <div id="success-message-bottom" class="success-message" hidden>
            
                <h2>Listening!</h2>
            </div>
        </form>
        </div>
    </div>

    <div id="main" class="main-content" hidden>
        <form action="#">
            <button id="sifon" type="submit" class="btn" hidden>Sifon</button>
            <button id="pisuvar" type="submit" class="btn" hidden>Pisuvar</button>
            <button id="sabunluk" type="submit" class="btn" hidden>Sabunluk</button>
            <button id="zPecete" type="submit" class="btn" hidden>Peçetelik</button>
            <button id="rulo" type="submit" class="btn" hidden>Rulo</button>
        </form>
    </div>
    <div class="burger-menu" onclick="toggleMenu()">
        <span></span>
        <span></span>
        <span></span>
    </div>

    <div class="float-container" id="containersabunluk" style="display: none;">
        
        
    </div>
    <div class="float-container" id="containersifon" style="display: none;">
        
    
    </div>
    <div class="float-container" id="containerpisuvar" style="display: none;">
        
        
    </div>
    <div class="float-container" id="containerzPecete" style="display: none;">
        
        
    </div>
    <div class="float-container" id="containerrulo" style="display: none;">
        
        
    </div>


</body>



    <script type="text/javascript">
        var tabPressCount = 0;
        var stopButtonClicked = false;

        var lastField1Value, lastField2Value, lastField3Value;
        var pisuvarValue = 0, sifonValue = 0, sabunlukValue = 0, zPeceteValue = 0, ruloValue = 0;
        var pisuvarID = [], sifonID = [], sabunlukID = [], zPeceteID = [], ruloID = [];

        const sabunlukButton = document.getElementById('sabunluk');
        const sifonButton = document.getElementById('sifon');
        const pisuvarButton = document.getElementById('pisuvar');
        const zPeceteButton = document.getElementById('zPecete');
        const ruloButton = document.getElementById('rulo');
        const backButton = document.getElementById('backButton');
        const listenButton = document.getElementById('listenButton');
        const stopButton = document.getElementById('stopButton');
        const field1 = document.getElementById('field1');
        const field2 = document.getElementById('field2');
        const field3 = document.getElementById('field3');
        const mainContent = document.querySelector('.main-content');
        const container = document.getElementById('settingsContainer');
        function toggleMenu() {
            const container = document.querySelector('.container');
            
            if (container.classList.contains('move-left')) {
                // Remove the 'move-left' class and set the display to 'none'
                container.classList.remove('move-left');
                container.style.display = 'none'; // Hide the container
            } else {
                // Add the 'move-left' class and set the display to 'flex'
                container.classList.add('move-left');
                container.style.display = 'flex'; // Show the container
            }
        }


        var xmlHttp = createXmlHttpObject();

        function createXmlHttpObject() {
            return window.XMLHttpRequest ? new XMLHttpRequest() : new ActiveXObject("Microsoft.XMLHTTP");
        }

        function toggleElementVisibility(elementId, show) {
            document.getElementById(elementId).style.display = show ? 'flex' : 'none';
        }

        function handleModuleButtonClick(buttonId, containerId) {
            const button = document.getElementById(buttonId); 
            const existingText = button.innerHTML.split(' ')[0];
            
            document.getElementById(buttonId).addEventListener('click', (event) => {
                event.preventDefault();
                const title = document.getElementById('selectedContainer');
                title.textContent = existingText.toUpperCase();
                mainContent.classList.remove('show');
                toggleElementVisibility(containerId, true);
                toggleElementVisibility('selectedContainer', true);
                backButton.hidden = false;
            });
        }

        handleModuleButtonClick('sabunluk', 'containersabunluk');
        handleModuleButtonClick('sifon', 'containersifon');
        handleModuleButtonClick('pisuvar', 'containerpisuvar');
        handleModuleButtonClick('rulo', 'containerrulo');
        handleModuleButtonClick('zPecete', 'containerzPecete');

        backButton.addEventListener('click', (event) => {
            event.preventDefault();
            backUI();
        });

        listenButton.addEventListener('click', (event) => {
            event.preventDefault();
            ['containersabunluk', 'containersifon', 'containerpisuvar', 'containerzPecete', 'containerrulo','selectedContainer'].forEach(id => toggleElementVisibility(id, false));

            const field1Value = field1.value.trim();
            const field2Value = field2.value.trim();
            const field3Value = field3.value.trim();
            const params = field1Value.split(':'); // Split by ':'

            if (params.length !== 6) {
                alert("P2P Configuration Error.");
                return;
            }

            const intParams = params.map(param => parseInt(param, 10));

            // Ensure all params are valid integers
            if (intParams.some(isNaN)) {
                alert("P2P Configuration Error.");
                return;
            }

            // Validate params
            if (!(intParams[0] >= 150000000 && intParams[0] <= 960000000 &&
                intParams[1] >= 5 && intParams[1] <= 12 &&
                [125, 250, 500].includes(intParams[2]) &&
                [0, 1, 2, 3].includes(intParams[3]) &&
                intParams[4] >= 2 && intParams[4] <= 65535 &&
                intParams[5] >= 5 && intParams[5] <= 22)) {
                alert("P2P Configuration Error.");
                return;
            }

            // Validate field2Value
            const field2ValueInt = parseInt(field2Value, 10);
            if (isNaN(field2ValueInt) || ![65534,65535].includes(field2ValueInt)) {
                alert("PRECV Error.");
                return;
            }
         
            if (!stopButtonClicked && field1Value === lastField1Value && field2Value === lastField2Value && field3Value === lastField3Value) return;
            
            if (!field1Value || !field2Value || !field3Value) {
                alert("Fields cannot be empty.");
                return;
            }

            lastField1Value = field1Value;
            lastField2Value = field2Value;
            lastField3Value = field3Value;

            resetModuleValues();
           

            fetchMahalData(field3Value);
            stopButtonClicked = false; 
        });

        stopButton.addEventListener('click', (event) => {
            event.preventDefault();
            resetUI();
            resetModuleValues();
            sendStopSignal();
            stopButtonClicked = true; 

        });

        document.getElementById("field1").addEventListener("keydown", handleTabPress);
        document.getElementById("field2").addEventListener("keydown", handleTabPress);

        function handleTabPress(event) {
            if (event.key === "Tab") {
                event.preventDefault();
                tabPressCount++;
                if (tabPressCount === 2) {
                    if (this.id === "field1") {
                        this.value = "868000000:7:125:0:8:22";
                    } else if (this.id === "field2") {
                        this.value = "65534";
                    }
                    tabPressCount = 0;
                }
            } else {
                tabPressCount = 0;
            }
        }

        function resetUI() {
            backButton.hidden = true;
            stopButton.hidden = true;
            listenButton.hidden = false;
            document.getElementById("success-message-bottom").hidden = true;
            mainContent.classList.remove('show');
            container.classList.remove('move-left');
            container.classList.add('move-right');

            ['containersabunluk', 'containersifon', 'containerpisuvar', 'containerzPecete', 'containerrulo','selectedContainer'].forEach(id => toggleElementVisibility(id, false));
        }

        function backUI() {
            backButton.hidden = true;
            stopButton.hidden = false;
            listenButton.hidden = false;
            document.getElementById("success-message-bottom").hidden = false;
            mainContent.classList.add('show');
            //container.classList.remove('move-left');
            

            ['containersabunluk', 'containersifon', 'containerpisuvar', 'containerzPecete', 'containerrulo','selectedContainer'].forEach(id => toggleElementVisibility(id, false));
        }

        function updateUIForListening(mahalData) {
            pisuvarButton.innerHTML = `Pisuvar 0/${pisuvarValue}`;
            sifonButton.innerHTML = `Sifon 0/${sifonValue}`;
            sabunlukButton.innerHTML = `Sabunluk 0/${sabunlukValue}`;
            zPeceteButton.innerHTML = `Peçetelik 0/${zPeceteValue}`;
            ruloButton.innerHTML = `Rulo 0/${ruloValue}`;

            ['pisuvar', 'sifon', 'sabunluk', 'zPecete', 'rulo'].forEach(id => toggleElementVisibility(id, eval(id + 'Value') > 0));

            mainContent.classList.add('show');
            container.classList.remove('move-right');
            container.classList.add('move-left');
            stopButton.hidden = false;
            document.getElementById("success-message-bottom").hidden = false;

            ['containersabunluk', 'containersifon', 'containerpisuvar', 'containerzPecete', 'containerrulo'].forEach(id => toggleElementVisibility(id, false));

            createBlocks(sabunlukValue, 'containersabunluk');
            createBlocks(sifonValue, 'containersifon');
            createBlocks(pisuvarValue, 'containerpisuvar');
            createBlocks(ruloValue, 'containerrulo');
            createBlocks(zPeceteValue, 'containerzPecete');
        }


        function resetModuleValues() {
            pisuvarValue = 0, sifonValue = 0, sabunlukValue = 0, zPeceteValue = 0, ruloValue = 0;
            pisuvarID = [], sifonID = [], sabunlukID = [], zPeceteID = [], ruloID = [];
        }

        function sendStopSignal() {
            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "BUTTON_STOP?stop=0", true);
            xhttp.send();
        }

        function fetchMahalData(mahalNo) {
            fetch('/veri.json')
                .then(response => {
                    if (!response.ok) throw new Error('Network response was not ok');
                    return response.json();
                })
                .then(data => {
                    const mahalData = data.data.find(d => d.tag === mahalNo);
                    if (mahalData) {
                        updateModuleValues(mahalData);
                        updateUIForListening(mahalData);
                        sendConfigToServer(mahalData.id, mahalData);
                    } else {
                        alert("Mahal No is not registered in the system.");
                        stopButton.click();
                    }
                })
                .catch(error => {
                    console.error('Fetch operation error:', error);
                    alert("There was an error fetching data. Please try again later.");
                });
        }

        function updateModuleValues(mahalData) {
            pisuvarValue = parseInt(mahalData.pisuvar, 10);
            sifonValue = parseInt(mahalData.sifon, 10);
            sabunlukValue = parseInt(mahalData.sabunluk, 10);
            zPeceteValue = parseInt(mahalData.peçetelik, 10);
            ruloValue = parseInt(mahalData.rulo, 10);
        }

        

        function sendConfigToServer(id, mahalData) {
            const xhttp = new XMLHttpRequest();
            xhttp.open("PUT", `BUTTON?config=${encodeURIComponent(field1.value)}&precv=${encodeURIComponent(field2.value)}&id=${encodeURIComponent(id)}&sabunluk=${encodeURIComponent(sabunlukValue)}&sifon=${encodeURIComponent(sifonValue)}&pisuvar=${encodeURIComponent(pisuvarValue)}&zPecete=${encodeURIComponent(zPeceteValue)}&rulo=${encodeURIComponent(ruloValue)}`, true);
            xhttp.send();
        }


        
        function createBlocks(len, name) {
            const container = document.getElementById(name);
            container.innerHTML = '';
            if (len <= 0) {
                console.error("Length must be a positive number");
                return;
            }
            for (let i = 0; i < len; i++) {
                const block = document.createElement('div');
                block.className = 'float-child';
                block.id = `block${name}-${i}`;
                block.innerHTML = `
                    <div class="device-id">Device ${i + 1}</div>
                    <div class="central-text">
                        Sensor Value: 0<br>
                        Battery: 0
                    </div>
                    <div class="status">
                        Status: Waiting
                        <div class="spinner-container">
                            <div class="spinner"></div>
                            <div class="spinner"></div>
                            <div class="spinner"></div>
                        </div>
                    </div>`;
                container.appendChild(block);
            }
        }




        function updateBlockContent(blockId, newStatusText, newCentralText = '') {
            const block = document.getElementById(blockId);

            // Update the status text if provided
            if (newStatusText !== undefined) {
                const status = block.querySelector('.status');
                status.innerHTML = newStatusText; // Use innerHTML to support HTML content
            }

            // Update the central text if provided
            if (newCentralText !== undefined) {
                const centralText = block.querySelector('.central-text');
                centralText.innerHTML = newCentralText; // Use innerHTML to support HTML content
            }
        }


        function process() {
            if (xmlHttp.readyState === 0 || xmlHttp.readyState === 4) {
                xmlHttp.open("PUT", "xml", true);
                xmlHttp.onreadystatechange = response;
                xmlHttp.send(null);
            }
            setTimeout(process, 100);
        }

        function response() {
            var xmlResponse = xmlHttp.responseXML;
            var xmldoc = xmlResponse.getElementsByTagName("id");
            var message = xmldoc[0].firstChild.nodeValue;
            var dt = new Date();

            // Update time and date
            document.getElementById("time").innerHTML = dt.toLocaleTimeString();
            document.getElementById("date").innerHTML = dt.toLocaleDateString();

            send(message);
        }


        function send(msg) {
            let moduleNumber = msg.substring(0, 2);
            let id = msg.substring(2, 4);
            const idInt = parseInt(id, 10);

            const updateIDArray = (array, id, msg) => {
                let index = array.findIndex(item => item[0] === id);
                if (index === -1) {
                    array.push([id, parseInt(msg.substring(4, 6), 16), parseInt(msg.substring(6, 8), 16), msg.substring(4, 6), msg.substring(6, 8)]);
                } else {
                    array[index][1] = parseInt(msg.substring(4, 6),16);
                    array[index][2] = parseInt(msg.substring(6, 8),16);
                    array[index][3] = msg.substring(4, 6);
                    array[index][4] = msg.substring(6, 8);
                }
            };

            switch (moduleNumber) {
                case "41":
                    updateIDArray(sabunlukID, id, msg);
                    updateBlockContent(
                        `blockcontainersabunluk-${idInt - 31}`,
                        'Status: Received',
                        `Sensor Value: ${sabunlukID[sabunlukID.length - 1][2]} / ${sabunlukID[sabunlukID.length - 1][4]}<br>Battery: ${sabunlukID[sabunlukID.length - 1][1]}% / ${sabunlukID[sabunlukID.length - 1][3]}`
                    );
                    updateButton(sabunlukButton, sabunlukID.length, sabunlukValue);
                    break;
                case "42":
                    updateIDArray(zPeceteID, id, msg);
                    updateBlockContent(
                        `blockcontainerzPecete-${idInt - 31}`,
                        'Status: Received',
                        `Sensor Value: ${zPeceteID[zPeceteID.length - 1][2]} / ${zPeceteID[zPeceteID.length - 1][4]}<br>Battery: ${zPeceteID[zPeceteID.length - 1][1]}% / ${zPeceteID[zPeceteID.length - 1][3]}`
                    );
                    updateButton(zPeceteButton, zPeceteID.length, zPeceteValue);
                    break;
                case "43":
                    updateIDArray(ruloID, id, msg);
                    updateBlockContent(
                        `blockcontainerrulo-${idInt - 31}`,
                        'Status: Received',
                        `Sensor Value: ${ruloID[ruloID.length - 1][2]} / ${ruloID[ruloID.length - 1][4]}<br>Battery: ${ruloID[ruloID.length - 1][1]}% / ${ruloID[ruloID.length - 1][3]}`
                    );
                    updateButton(ruloButton, ruloID.length, ruloValue);
                    break;
                case "44":
                    updateIDArray(pisuvarID, id, msg);
                    updateBlockContent(
                        `blockcontainerpisuvar-${idInt - 31}`,
                        'Status: Received',
                        `Sensor Value: ${pisuvarID[pisuvarID.length - 1][2]} / ${pisuvarID[pisuvarID.length - 1][4]}<br>Battery: ${pisuvarID[pisuvarID.length - 1][1]}% / ${pisuvarID[pisuvarID.length - 1][3]}`
                    );
                    updateButton(pisuvarButton, pisuvarID.length, pisuvarValue);
                    break;
                case "45":
                    updateIDArray(sifonID, id, msg);
                    updateBlockContent(
                        `blockcontainersifon-${idInt - 31}`,
                        'Status: Received',
                        `Sensor Value: ${sifonID[sifonID.length - 1][2]} / ${sifonID[sifonID.length - 1][4]}<br>Battery: ${sifonID[sifonID.length - 1][1]}% / ${sifonID[sifonID.length - 1][3]}`
                    );
                    updateButton(sifonButton, sifonID.length, sifonValue);
                    break;
            }

        }


        function updateButton(button, length, totalValue) {
            
            const existingText = button.innerHTML.split(' ')[0];
            
            button.innerHTML = `${existingText} ${length}/${totalValue}`;
        }


    </script>




</html>
)=====";
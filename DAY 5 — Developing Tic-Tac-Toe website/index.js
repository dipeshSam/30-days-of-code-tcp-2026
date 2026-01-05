const cells = document.querySelectorAll(".cell");
const statusText = document.getElementById("status");
const restartBtn = document.getElementById("restart");
const board = document.querySelector(".board");

let currentPlayer = "X";
let gameActive = true;
let state = Array(9).fill("");

const wins = [
    [0,1,2],[3,4,5],[6,7,8],
    [0,3,6],[1,4,7],[2,5,8],
    [0,4,8],[2,4,6]
];

cells.forEach(cell => cell.addEventListener("click", handleClick));
restartBtn.addEventListener("click", resetGame);

function handleClick(e) {
    const index = e.target.dataset.index;

    if (!gameActive || state[index]) return;

    state[index] = currentPlayer;
    e.target.textContent = currentPlayer;
    e.target.classList.add(currentPlayer);

    if (checkWin()) {
        statusText.textContent = `Player ${currentPlayer} wins!`;
        gameActive = false;
        return;
    }

    if (!state.includes("")) {
        statusText.textContent = "It's a draw!";
        board.classList.add("draw");
        gameActive = false;
        return;
    }

    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.textContent = `Player ${currentPlayer}'s turn`;
}

function checkWin() {
    for (let combo of wins) {
        const [a,b,c] = combo;
        if (state[a] && state[a] === state[b] && state[a] === state[c]) {
            combo.forEach(i => cells[i].classList.add("win"));
            return true;
        }
    }
    return false;
}

function resetGame() {
    currentPlayer = "X";
    gameActive = true;
    state.fill("");
    statusText.textContent = "Player X's turn";
    board.classList.remove("draw");

    cells.forEach(cell => {
        cell.textContent = "";
        cell.className = "cell";
    });
}

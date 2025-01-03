async function fetchMarkdown() {
    const url = 'https://raw.githubusercontent.com/milosz275/leetcode/main/README.md';
    const response = await fetch(url);
    const data = await response.text();
    return data;
}

function extractTable(markdown) {
    const tableStart = markdown.indexOf("## All Problems");
    let tableEnd = markdown.indexOf("## License");
    const commentEndIndex = markdown.indexOf("<!--");
    if (commentEndIndex !== -1 && commentEndIndex < tableEnd) {
        tableEnd = commentEndIndex;
    }
    let tableMarkdown = markdown.substring(tableStart, tableEnd);
    return tableMarkdown;
}

function prependGitHubURL(tableMarkdown) {
    const githubBaseURL = 'https://github.com/milosz275/leetcode/blob/main/';
    const regex = /\[([^\]]+)\]\(([^)]+\.(c|cpp|py))\)/g;
    const modifiedMarkdown = tableMarkdown.replace(regex, (match, linkText, filePath) => {
        return `[${linkText}](${githubBaseURL}${filePath})`;
    });
    return modifiedMarkdown;
}

function displayTable(tableMarkdown) {
    const html = marked.parse(tableMarkdown);
    document.getElementById('markdownTable').innerHTML = html;
    makeHeadersSortable();
    addCursorPointerToHeaders();
}

function addCursorPointerToHeaders() {
    const style = document.createElement('style');
    style.type = 'text/css';
    style.innerHTML = `#markdownTable th { cursor: pointer; }`;
    document.getElementsByTagName('head')[0].appendChild(style);
}

function makeHeadersSortable() {
    const table = document.querySelector('#markdownTable table');
    if (!table) return;
    const headers = table.querySelectorAll('th');
    const tableBody = table.querySelector('tbody');
    const rows = Array.from(tableBody.querySelectorAll('tr'));

    const difficultyOrder = { 'Easy': 1, 'Medium': 2, 'Hard': 3 };

    const getCellValue = (row, index) => row.children[index].innerText || row.children[index].textContent;

    const comparer = (index, asc) => (a, b) => {
        if (headers[index].textContent.replace(/ \u2193|\u2191/, '') === 'Difficulty') {
            return (asc ? 1 : -1) * (difficultyOrder[getCellValue(a, index)] - difficultyOrder[getCellValue(b, index)]);
        } else {
            const valueA = getCellValue(a, index), valueB = getCellValue(b, index);
            return valueA !== '' && valueB !== '' && !isNaN(valueA) && !isNaN(valueB) ? 
                (asc ? 1 : -1) * (valueA - valueB) : 
                (asc ? 1 : -1) * valueA.toString().localeCompare(valueB);
        }
    };

    headers.forEach((header, index) => {
        header.addEventListener('click', () => {
            const currentSort = header.getAttribute('data-sort');
            const newSort = currentSort === 'asc' ? 'desc' : 'asc';
            headers.forEach(h => {
                h.setAttribute('data-sort', '');
                h.textContent = h.textContent.replace(/ \u2193|\u2191/, '');
            });
            header.setAttribute('data-sort', newSort);
    
            header.textContent += newSort === 'asc' ? ' \u2193' : ' \u2191';
    
            const isDifficulty = header.textContent.includes('Difficulty');
            rows.sort((a, b) => {
                let valueA = getCellValue(a, index);
                let valueB = getCellValue(b, index);
    
                if (isDifficulty) {
                    valueA = difficultyOrder[valueA];
                    valueB = difficultyOrder[valueB];
                } else {
                    valueA = isNaN(valueA) ? valueA : parseFloat(valueA);
                    valueB = isNaN(valueB) ? valueB : parseFloat(valueB);
                }
    
                if (valueA < valueB) return newSort === 'asc' ? -1 : 1;
                if (valueA > valueB) return newSort === 'asc' ? 1 : -1;
                return 0;
            }).forEach(row => tableBody.appendChild(row));
        });
    });
}

function loadDarkMode() {
    let darkMode = localStorage.getItem("dark");
    if (darkMode === null) {
        darkMode = window.matchMedia("(prefers-color-scheme: dark)").matches;
    } else {
        darkMode = JSON.parse(darkMode);
    }
    document.documentElement.classList.toggle("dark", darkMode);
}

document.addEventListener("DOMContentLoaded", loadDarkMode);

function toggleDarkMode() {
    document.documentElement.classList.toggle("dark");
    let darkMode = document.documentElement.classList.contains("dark");
    localStorage.setItem("dark", JSON.stringify(darkMode));
}

async function init() {
    const markdown = await fetchMarkdown();
    let tableMarkdown = extractTable(markdown);
    tableMarkdown = prependGitHubURL(tableMarkdown);
    displayTable(tableMarkdown);
}

init();

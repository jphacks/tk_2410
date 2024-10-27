// import React from "react";
// import { useState, useEffect } from "react";

// const containerStyle: React.CSSProperties = {
//   justifyContent: "center",
//   alignItems: "flex-start",
//   minHeight: "100vh",
//   width: "fit-content",
//   margin: "0 auto",
//   padding: "20px",
// };

// const verticalTextStyle: React.CSSProperties = {
//   writingMode: "vertical-rl",
//   textOrientation: "upright",
//   whiteSpace: "pre-wrap",
//   lineHeight: "2",
//   maxHeight: "calc(100vh - 40px)",
//   overflowY: "auto",
//   textAlign: "left",
//   fontSize: "2rem",
//   fontWeight: "400",
//   letterSpacing: "0.05em",
// };

// const NovelPage: React.FC = () => {
//   const [textContent, setTextContent] = useState<string>("");

//   useEffect(() => {
//     fetch("../../public/message.txt")
//       .then((response) => response.text())
//       .then((data) => setTextContent(data))
//       .catch((error) => console.error("Error loading text file:", error));
//   }, []);

//   return (
//     <div style={containerStyle}>
//       <div style={verticalTextStyle}>
//         {textContent.split("<br/>").map((line, index) => (
//           <React.Fragment key={index}>
//             {line}
//             <br />
//           </React.Fragment>
//         ))}
//       </div>
//     </div>
//   );
// };

// export default NovelPage;

// import React, { useState, useEffect, CSSProperties } from "react";

// const verticalTextStyle: CSSProperties = {
//   writingMode: "vertical-rl",
//   textOrientation: "upright",
//   whiteSpace: "pre-wrap",
//   lineHeight: "2",
//   maxHeight: "calc(100vh - 40px)",
//   overflowY: "auto",
//   textAlign: "left",
//   fontSize: "2rem",
//   fontWeight: "400",
//   letterSpacing: "0.05em",
// };

// const containerStyle: CSSProperties = {
//   display: "flex",
//   justifyContent: "center",
//   alignItems: "flex-start",
//   minHeight: "100vh",
//   width: "fit-content",
//   margin: "0 auto",
//   padding: "20px",
// };

// const AnimatedNovelPage = () => {
//   const [textContent, setTextContent] = useState("");
//   const [displayText, setDisplayText] = useState("");
//   const [currentIndex, setCurrentIndex] = useState(0);
//   const [isPaused, setIsPaused] = useState(false);

//   useEffect(() => {
//     fetch("../../public/message.txt")
//       .then((response) => response.text())
//       .then((data) => setTextContent(data))
//       .catch((error) => console.error("Error loading text file:", error));
//   }, []);

//   useEffect(() => {
//     if (!textContent || currentIndex >= textContent.length) return;

//     const timer = setTimeout(() => {
//       if (!isPaused) {
//         setDisplayText((prev) => prev + textContent[currentIndex]);
//         setCurrentIndex((prev) => prev + 1);
//       }
//     }, 50);

//     return () => clearTimeout(timer);
//   }, [textContent, currentIndex, isPaused]);

//   const handleClick = () => {
//     setIsPaused((prev) => !prev);
//   };

//   return (
//     <div style={containerStyle}>
//       <div style={verticalTextStyle} onClick={handleClick}>
//         {displayText.split("<br/>").map((line, index) => (
//           <React.Fragment key={index}>
//             {line}
//             <br />
//           </React.Fragment>
//         ))}
//       </div>
//     </div>
//   );
// };

// export default AnimatedNovelPage;

import { CSSProperties, useEffect, useState } from "react";

const verticalTextStyle: CSSProperties = {
  writingMode: "vertical-rl",
  textOrientation: "upright",
  whiteSpace: "pre-wrap",
  lineHeight: "2",
  maxHeight: "calc(100vh - 40px)",
  overflowY: "auto",
  textAlign: "left",
  fontSize: "2rem",
  fontWeight: "400",
  letterSpacing: "0.05em",
};

const containerStyle: CSSProperties = {
  display: "flex",
  justifyContent: "center",
  alignItems: "flex-start",
  minHeight: "100vh",
  width: "fit-content",
  margin: "0 auto",
  padding: "20px",
};

const lineStyle: CSSProperties = {
  marginBottom: "1rem",
};

const AnimatedNovelPage = () => {
  const [textContent, setTextContent] = useState("");
  const [displayLines, setDisplayLines] = useState<string[]>([]);
  const [currentIndex, setCurrentIndex] = useState(0);
  const [currentLineIndex, setCurrentLineIndex] = useState(0);
  const [isPaused, setIsPaused] = useState(false);

  useEffect(() => {
    fetch("../../public/message.txt")
      .then((response) => response.text())
      .then((data) => {
        const lines = data.split("<br/>").filter((line) => line.trim() !== "");
        setTextContent(data);
        setDisplayLines(lines.map(() => ""));
      })
      .catch((error) => console.error("Error loading text file:", error));
  }, []);

  useEffect(() => {
    if (!textContent || currentLineIndex >= displayLines.length) return;

    const lines = textContent
      .split("<br/>")
      .filter((line) => line.trim() !== "");
    const currentLine = lines[currentLineIndex];

    if (currentIndex >= currentLine.length) {
      if (currentLineIndex < lines.length - 1) {
        setCurrentLineIndex((prev) => prev + 1);
        setCurrentIndex(0);
      }
      return;
    }

    const timer = setTimeout(() => {
      if (!isPaused) {
        setDisplayLines((prev) => {
          const newLines = [...prev];
          newLines[currentLineIndex] = currentLine.substring(
            0,
            currentIndex + 1
          );
          return newLines;
        });
        setCurrentIndex((prev) => prev + 1);
      }
    }, 50);

    return () => clearTimeout(timer);
  }, [textContent, currentIndex, currentLineIndex, isPaused]);

  const handleClick = () => {
    setIsPaused((prev) => !prev);
  };

  return (
    <div style={containerStyle}>
      <div style={verticalTextStyle} onClick={handleClick}>
        {displayLines.map((line, index) => (
          <div key={index} style={lineStyle}>
            {line}
          </div>
        ))}
      </div>
    </div>
  );
};

export default AnimatedNovelPage;

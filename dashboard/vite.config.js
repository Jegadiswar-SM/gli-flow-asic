import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
  plugins: [
    react(),
    tailwindcss(),
  ],
  server: {
    proxy: {
      "/runs": "http://127.0.0.1:8000",
      "/live_runs": "http://127.0.0.1:8000",
      "/trends": "http://127.0.0.1:8000",
      "/releases": "http://127.0.0.1:8000",
      "/health": "http://127.0.0.1:8000",
    },
  },
})

from pathlib import Path
from typing import List


LAYOUT_IMAGE_NAMES = [
    "final_all",
    "final_placement",
    "final_routing",
    "final_clocks",
    "final_ir_drop",
]


def generate_placeholder_images(reports_dir: str | Path) -> List[str]:
    reports_dir = Path(reports_dir)
    reports_dir.mkdir(parents=True, exist_ok=True)

    generated = []
    for name in LAYOUT_IMAGE_NAMES:
        webp_path = reports_dir / f"{name}.webp"
        png_path = reports_dir / f"{name}.png"
        if webp_path.exists() or png_path.exists():
            continue
        try:
            _create_placeholder_webp(webp_path, name)
            generated.append(str(webp_path))
        except Exception:
            try:
                _create_placeholder_png(png_path, name)
                generated.append(str(png_path))
            except Exception:
                pass
    return generated


def _create_placeholder_webp(path: Path, name: str) -> None:
    from PIL import Image, ImageDraw

    w, h = 800, 600
    bg = {
        "final_all": (26, 35, 126),
        "final_placement": (27, 94, 32),
        "final_routing": (0, 77, 64),
        "final_clocks": (74, 20, 140),
        "final_ir_drop": (183, 28, 28),
    }.get(name, (50, 50, 50))

    img = Image.new("RGB", (w, h), bg)
    draw = ImageDraw.Draw(img)

    margin = 40
    die_w = w - 2 * margin
    die_h = h - 2 * margin

    draw.rectangle([margin, margin, margin + die_w, margin + die_h], outline=(255, 255, 255, 80), width=2)

    if name == "final_all":
        import random
        rng = random.Random(42)
        for _ in range(12):
            x = margin + rng.randint(0, die_w - 80)
            y = margin + rng.randint(0, die_h - 60)
            rw = rng.randint(20, 80)
            rh = rng.randint(15, 60)
            c = (rng.randint(100, 255), rng.randint(100, 255), rng.randint(100, 255))
            draw.rectangle([x, y, x + rw, y + rh], fill=c, outline=(255, 255, 255))
        for _ in range(30):
            x1 = margin + rng.randint(0, die_w)
            y1 = margin + rng.randint(0, die_h)
            x2 = margin + rng.randint(0, die_w)
            y2 = margin + rng.randint(0, die_h)
            draw.line([x1, y1, x2, y2], fill=(200, 200, 100, 120), width=1)

    elif name == "final_placement":
        import random
        rng = random.Random(7)
        for _ in range(20):
            x = margin + rng.randint(0, die_w - 60)
            y = margin + rng.randint(0, die_h - 40)
            rw = rng.randint(15, 60)
            rh = rng.randint(10, 40)
            c = (rng.randint(80, 200), rng.randint(180, 255), rng.randint(80, 200))
            draw.rectangle([x, y, x + rw, y + rh], fill=c, outline=(255, 255, 255))
            draw.text((x + 2, y + 2), f"B{rng.randint(0, 99)}", fill=(255, 255, 255))

    elif name == "final_routing":
        import random
        rng = random.Random(99)
        for _ in range(40):
            x1 = margin + rng.randint(0, die_w)
            y1 = margin + rng.randint(0, die_h)
            x2 = margin + rng.randint(0, die_w)
            y2 = margin + rng.randint(0, die_h)
            draw.line([x1, y1, x2, y2], fill=(rng.randint(150, 255), rng.randint(150, 255), 200), width=rng.randint(1, 3))
        for _ in range(6):
            x = margin + rng.randint(0, die_w - 40)
            y = margin + rng.randint(0, die_h - 40)
            rw = rng.randint(20, 40)
            rh = rng.randint(20, 40)
            draw.rectangle([x, y, x + rw, y + rh], fill=(100, 180, 200), outline=(200, 255, 255))

    elif name == "final_clocks":
        cx, cy = w // 2, h // 2
        draw.ellipse([cx - 5, cy - 5, cx + 5, cy + 5], fill=(255, 255, 0))
        import random
        rng = random.Random(13)
        for _ in range(12):
            angle = rng.uniform(0, 360)
            import math
            rad = math.radians(angle)
            length = rng.randint(60, 200)
            ex = int(cx + length * math.cos(rad))
            ey = int(cy + length * math.sin(rad))
            draw.line([cx, cy, ex, ey], fill=(255, 255, 100), width=2)
            for _ in range(4):
                off = rng.randint(10, length - 10)
                ox = int(cx + off * math.cos(rad))
                oy = int(cy + off * math.sin(rad))
                draw.ellipse([ox - 3, oy - 3, ox + 3, oy + 3], fill=(100, 255, 200))

    elif name == "final_ir_drop":
        import random
        rng = random.Random(88)
        for y in range(margin, margin + die_h, 8):
            t = (y - margin) / die_h
            r = int(183 * t + 26 * (1 - t))
            g = int(28 * t + 35 * (1 - t))
            b = int(28 * t + 126 * (1 - t))
            draw.line([margin, y, margin + die_w, y], fill=(r, g, b))
        for _ in range(15):
            x = margin + rng.randint(0, die_w)
            y = margin + rng.randint(0, die_h)
            draw.ellipse([x - 15, y - 15, x + 15, y + 15], fill=(255, 100, 50, 100), outline=(255, 200, 100))

    draw.text((w // 2 - 60, 8), name.replace("_", " ").title(), fill=(255, 255, 255))
    draw.text((w // 2 - 80, h - 20), "Placeholder Layout View", fill=(200, 200, 200))

    img.save(str(path), "WEBP", quality=85)


def _create_placeholder_png(path: Path, name: str) -> None:
    from PIL import Image, ImageDraw

    w, h = 800, 600
    bg = {
        "final_all": (26, 35, 126),
        "final_placement": (27, 94, 32),
        "final_routing": (0, 77, 64),
        "final_clocks": (74, 20, 140),
        "final_ir_drop": (183, 28, 28),
    }.get(name, (50, 50, 50))

    img = Image.new("RGB", (w, h), bg)
    draw = ImageDraw.Draw(img)

    draw.rectangle([40, 40, w - 40, h - 40], outline=(255, 255, 255), width=2)
    draw.text((w // 2 - 60, h // 2 - 10), name.replace("_", " ").title(), fill=(255, 255, 255))
    draw.text((w // 2 - 80, h - 20), "Placeholder Layout View", fill=(200, 200, 200))

    img.save(str(path), "PNG")

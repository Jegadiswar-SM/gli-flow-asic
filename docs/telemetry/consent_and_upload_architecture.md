# GLI-FLOW Telemetry Consent, Auto-Upload & Trust Architecture

This document outlines the architecture for the GLI-FLOW telemetry system, designed to balance product improvement with user privacy and trust.

## 1. Consent Flow
- **First Launch**: Upon the first run of the CLI, a mandatory telemetry wizard is presented to the user.
- **Modes**: Users select from [Full], [Atlas Only], or [Local Only] modes.
- **Persistence**: Consent is recorded in `~/.gli-flow/telemetry_settings.json` and will not be requested again unless settings are reset or policy changes.
- **Migration**: Existing users are prompted for consent on the next launch; telemetry is not auto-enabled.

## 2. Upload Flow
- **Execution**: Telemetry is collected at every stage of the run.
- **Sanitization**: Before any data leaves the machine, it passes through the `TelemetryExporter` and `PrivacyValidator`.
- **Consent Check**: The `TelemetryUploader` verifies user consent and mode before initiating any transfer.
- **Background Upload**: Uploads occur in a detached background process to minimize latency and ensure a seamless experience.

## 3. Privacy Guarantees
- **Never Uploaded**: RTL, Netlists, DEF, LEF, GDS, Bitstreams, Liberty files, and Constraint contents are strictly blocked.
- **Sanitization**: All telemetry data is filtered through a privacy validator that removes sensitive fields.
- **Transparency**: Users can view the sanitized payload before upload using `gli-flow telemetry preview`.

## 4. Enterprise Behavior
- Enterprise deployments can disable telemetry via configuration (`telemetry_mode = disabled`).
- "Local Only" mode is supported for air-gapped or highly restrictive environments.

## 5. Dashboard Changes
- **Telemetry Status Center**: Added to the dashboard, showing mode, consent status, and upload success metrics.

## 6. CLI Changes
New `gli-flow telemetry` subcommands:
- `status`: Show current settings and metrics.
- `enable`: Enable full telemetry.
- `disable`: Disable all telemetry.
- `mode [full|atlas|local|disabled]`: Set/view mode.
- `preview`: View the payload before upload.
- `export`, `replay`, `health`, `snapshot`, `audit-log` (existing commands maintained).

## 7. Testing
Comprehensive test suite implemented covering:
- First-run wizard behavior.
- Consent persistence and migration.
- Upload logic (allowed vs denied based on mode).
- Privacy validator (sensitive field blocking).
- Local-only mode enforcement.
